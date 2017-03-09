
/**************************************************************************/
/*
	Advanced Games Engineering (CGP600) Module
	www.solent.ac.uk
	2016/17
		
	Aim of module:
	1. Extend and develop an open source game 
	2. Add additional platforms/API
	   o Vulkan Graphics API 
	   o DirectX 12
	3. Cross platform
	   o Win32/Win64
	   o PS4 
	   o Linux
	4. Include multi-player support 
	   o Networking/split screen
	5. Managed through version control 
	6. Include NPC (animated characters)
	7. Vehicle damage/smoke/deformation
	8. Customize and save
	
	
	Chosen Open Source Game for 2016/2017
	"Torcs"
	TORCS - The Open Racing Car Simulator download | SourceForge.net
	Homepage: https://sourceforge.net/projects/torcs/
	
	
	The module focuses on developing industry practices, working on 
	medium to to large code bases with the ability to add, customize, 
	or repair features.
/*
/**************************************************************************/

/***************************************************************************

    file                 : racemenu.cpp
    created              : Thu May  2 22:02:51 CEST 2002
    copyright            : (C) 2001 by Eric Espie
    email                : eric.espie@torcs.org
    version              : $Id: racemenu.cpp,v 1.2.2.3 2011/12/28 14:59:10 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

/** @file   
    		This is the race options menu.
    @ingroup	racemantools
    @author	<a href=mailto:eric.espie@torcs.org>Eric Espie</a>
    @version	$Id: racemenu.cpp,v 1.2.2.3 2011/12/28 14:59:10 berniw Exp $
*/

#include <stdlib.h>
#include <stdio.h>
#ifdef WIN32
#include <windows.h>
#endif
#include <tgfclient.h>
#include <track.h>
#include <car.h>
#include <raceman.h>
#include <robot.h>
#include <racescreens.h>
#include <portability.h>

static void		*scrHandle;
static tRmRaceParam	*rp;
static int		rmrpDistance;
static int		rmrpLaps;
static int		rmrpDistId;
static int		rmrpLapsId;
static int		rmDispModeEditId;
static int		rmCurDispMode;
static const char *rmCurDispModeList[] = { RM_VAL_VISIBLE, RM_VAL_INVISIBLE};


static void
rmrpDeactivate(void *screen)
{
    GfuiScreenRelease(scrHandle);
    
    if (screen) {
	GfuiScreenActivate(screen);
    }
}


static void
rmrpUpdDist(void * /* dummy */)
{
	char *val;
	const int BUFSIZE = 1024;
	char buf[BUFSIZE];

	val = GfuiEditboxGetString(scrHandle, rmrpDistId);
	rmrpDistance = strtol(val, (char **)NULL, 0);
	if (rmrpDistance == 0) {
		strcpy(buf, "---");
	} else {
		snprintf(buf, BUFSIZE, "%d", rmrpDistance);
		rmrpLaps = 0;
		GfuiEditboxSetString(scrHandle, rmrpLapsId, "---");
	}
	GfuiEditboxSetString(scrHandle, rmrpDistId, buf);
}


static void
rmrpUpdLaps(void * /* dummy */)
{
	char *val;
	const int BUFSIZE = 1024;
	char buf[BUFSIZE];

	val = GfuiEditboxGetString(scrHandle, rmrpLapsId);
	rmrpLaps = strtol(val, (char **)NULL, 0);
	if (rmrpLaps == 0) {
		strcpy(buf, "---");
	} else {
		snprintf(buf, BUFSIZE, "%d", rmrpLaps);
		rmrpDistance = 0;
		GfuiEditboxSetString(scrHandle, rmrpDistId, "---");
	}
	GfuiEditboxSetString(scrHandle, rmrpLapsId, buf);
}


static void
rmrpValidate(void * /* dummy */)
{
	if (rp->confMask & RM_CONF_RACE_LEN) {
		rmrpUpdDist(0);
		rmrpUpdLaps(0);
		GfParmSetNum(rp->param, rp->title, RM_ATTR_DISTANCE, "km", rmrpDistance);
		GfParmSetNum(rp->param, rp->title, RM_ATTR_LAPS, (char*)NULL, rmrpLaps);
	}

	if (rp->confMask & RM_CONF_DISP_MODE) {
		GfParmSetStr(rp->param, rp->title, RM_ATTR_DISPMODE, rmCurDispModeList[rmCurDispMode]);
	}

	rmrpDeactivate(rp->nextScreen);
}


static void
rmrpAddKeys(void)
{
	GfuiAddKey(scrHandle, 27, "Cancel Modifications", rp->prevScreen, rmrpDeactivate, NULL);
	GfuiAddSKey(scrHandle, GLUT_KEY_F1, "Help", scrHandle, GfuiHelpScreen, NULL);
	GfuiAddSKey(scrHandle, GLUT_KEY_F12, "Screen-Shot", NULL, GfuiScreenShot, NULL);
	GfuiAddKey(scrHandle, 13, "Validate Modifications", NULL, rmrpValidate, NULL);
}


void
rmChangeDisplayMode(void * /* dummy */)
{
	rmCurDispMode = 1 - rmCurDispMode;
	GfuiLabelSetText(scrHandle, rmDispModeEditId, rmCurDispModeList[rmCurDispMode]);
}


void
RmRaceParamMenu(void *vrp)
{
	int y, x, x2, dy, dx;
	const int BUFSIZE = 1024;
	char buf[BUFSIZE];

	rp = (tRmRaceParam*)vrp;
	
	snprintf(buf, BUFSIZE, "%s Options", rp->title);
	scrHandle = GfuiMenuScreenCreate(buf);
	GfuiScreenAddBgImg(scrHandle, "data/img/splash-raceopt.png");

	x = 80;
	x2 = 240;
	y = 380;
	dx = 200;
	dy = GfuiFontHeight(GFUI_FONT_LARGE) + 5;

	if (rp->confMask & RM_CONF_RACE_LEN) {
		GfuiLabelCreate(scrHandle, "Race Distance (km):", GFUI_FONT_MEDIUM_C, x, y, GFUI_ALIGN_HL_VB, 0);
		rmrpDistance = (int)GfParmGetNum(rp->param, rp->title, RM_ATTR_DISTANCE, "km", 0);
		if (rmrpDistance == 0) {
			strcpy(buf, "---");
			rmrpLaps = (int)GfParmGetNum(rp->param, rp->title, RM_ATTR_LAPS, NULL, 25);
		} else {
			snprintf(buf, BUFSIZE, "%d", rmrpDistance);
			rmrpLaps = 0;
		}
		
		rmrpDistId = GfuiEditboxCreate(scrHandle, buf, GFUI_FONT_MEDIUM_C,
						x + dx, y,
						0, 8, NULL, (tfuiCallback)NULL, rmrpUpdDist);

		y -= dy;
		GfuiLabelCreate(scrHandle, "Laps:", GFUI_FONT_MEDIUM_C, x, y, GFUI_ALIGN_HL_VB, 0);
		if (rmrpLaps == 0) {
			strcpy(buf, "---");
		} else {
			snprintf(buf, BUFSIZE, "%d", rmrpLaps);
		}
		
		rmrpLapsId = GfuiEditboxCreate(scrHandle, buf, GFUI_FONT_MEDIUM_C,
						x + dx, y,
						0, 8, NULL, (tfuiCallback)NULL, rmrpUpdLaps);
		y -= dy;
	}

	if (rp->confMask & RM_CONF_DISP_MODE) {
		GfuiLabelCreate(scrHandle, "Display:", GFUI_FONT_MEDIUM_C, x, y, GFUI_ALIGN_HL_VB, 0);
		GfuiGrButtonCreate(scrHandle, "data/img/arrow-left.png", "data/img/arrow-left.png",
				"data/img/arrow-left.png", "data/img/arrow-left-pushed.png",
				x2, y, GFUI_ALIGN_HL_VB, 1,
				(void*)0, rmChangeDisplayMode,
				NULL, (tfuiCallback)NULL, (tfuiCallback)NULL);	    
		GfuiGrButtonCreate(scrHandle, "data/img/arrow-right.png", "data/img/arrow-right.png",
				"data/img/arrow-right.png", "data/img/arrow-right-pushed.png",
				x2 + 150, y, GFUI_ALIGN_HL_VB, 1,
				(void*)1, rmChangeDisplayMode,
				NULL, (tfuiCallback)NULL, (tfuiCallback)NULL);
		if (!strcmp(GfParmGetStr(rp->param, rp->title, RM_ATTR_DISPMODE, RM_VAL_VISIBLE), RM_VAL_INVISIBLE)) {
			rmCurDispMode = 1;
		} else {
			rmCurDispMode = 0;
		}
		rmDispModeEditId = GfuiLabelCreate(scrHandle, rmCurDispModeList[rmCurDispMode], GFUI_FONT_MEDIUM_C, x2 + 35, y, GFUI_ALIGN_HL_VB, 20);
		y -= dy;
	}

	GfuiButtonCreate(scrHandle, "Accept", GFUI_FONT_LARGE, 210, 40, 150, GFUI_ALIGN_HC_VB, GFUI_MOUSE_UP,
				NULL, rmrpValidate, NULL, NULL, NULL);

	GfuiButtonCreate(scrHandle, "Cancel", GFUI_FONT_LARGE, 430, 40, 150, GFUI_ALIGN_HC_VB, GFUI_MOUSE_UP,
				rp->prevScreen, rmrpDeactivate, NULL, NULL, NULL);

	rmrpAddKeys();

	GfuiScreenActivate(scrHandle);
}
