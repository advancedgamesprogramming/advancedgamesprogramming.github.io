
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
                       guihelp.cpp -- automatic help on keys                                
                             -------------------                                         
    created              : Fri Aug 13 22:20:37 CEST 1999
    copyright            : (C) 1999 by Eric Espie                         
    email                : torcs@free.fr   
    version              : $Id: guihelp.cpp,v 1.3 2004/02/28 08:39:13 torcs Exp $                                  
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
    		GUI help screen management.
    @author	<a href=mailto:torcs@free.fr>Eric Espie</a>
    @version	$Id: guihelp.cpp,v 1.3 2004/02/28 08:39:13 torcs Exp $
    @ingroup	gui
*/

#include <stdlib.h>
#ifdef WIN32
#include <windows.h>
#endif
#include <tgfclient.h>
#include "gui.h"

static void	*scrHandle;
static float	*fgColor1 = &(GfuiColor[GFUI_HELPCOLOR1][0]);
static float	*fgColor2 = &(GfuiColor[GFUI_HELPCOLOR2][0]);

void
gfuiHelpInit(void)
{
}

/** Generate a help screen.
    @ingroup	gui
    @param	prevScreen	Previous screen to return to
    @warning	The help screen is activated.
 */
void
GfuiHelpScreen(void *prevScreen)
{
    int		x, x2, dx, y;
    tGfuiKey	*curKey;
    tGfuiKey	*curSKey;
    tGfuiScreen	*pscr = (tGfuiScreen*)prevScreen;
    
    scrHandle = GfuiScreenCreate();
    
    GfuiLabelCreateEx(scrHandle,
		      "Keys Definition",
		      fgColor2,
		      GFUI_FONT_BIG,
		      320,
		      440,
		      GFUI_ALIGN_HC_VB,
		      0);

    x  = 30;
    dx = 80;
    x2 = 330;
    y  = 380;
    
    curSKey = pscr->userSpecKeys;
    curKey = pscr->userKeys;
    do {
	if (curSKey != NULL) {
	    curSKey = curSKey->next;
	    GfuiLabelCreateEx(scrHandle, curSKey->name, fgColor1, GFUI_FONT_SMALL_C, x, y, GFUI_ALIGN_HL_VB, 0);
	    GfuiLabelCreateEx(scrHandle, curSKey->descr, fgColor2, GFUI_FONT_SMALL_C, x + dx, y, GFUI_ALIGN_HL_VB, 0);
	}

	if (curKey != NULL) {
	    curKey = curKey->next;
	    GfuiLabelCreateEx(scrHandle, curKey->name, fgColor1, GFUI_FONT_SMALL_C, x2, y, GFUI_ALIGN_HL_VB, 0);
	    GfuiLabelCreateEx(scrHandle, curKey->descr, fgColor2, GFUI_FONT_SMALL_C, x2 + dx, y, GFUI_ALIGN_HL_VB, 0);
	}
	y -= 12;
	
	if (curKey == pscr->userKeys) curKey = (tGfuiKey*)NULL;
	if (curSKey == pscr->userSpecKeys) curSKey = (tGfuiKey*)NULL;

    } while ((curKey != NULL) || (curSKey != NULL));
    

    GfuiButtonCreate(scrHandle,
		     "Back",
		     GFUI_FONT_LARGE,
		     320,
		     40,
		     GFUI_BTNSZ,
		     GFUI_ALIGN_HC_VB,
		     0,
		     prevScreen,
		     GfuiScreenActivate,
		     NULL,
		     (tfuiCallback)NULL,
		     (tfuiCallback)NULL);

    GfuiAddKey(scrHandle, (unsigned char)27, "", prevScreen, GfuiScreenReplace, NULL);
    GfuiAddSKey(scrHandle, GLUT_KEY_F1, "", prevScreen, GfuiScreenReplace, NULL);
    GfuiAddKey(scrHandle, (unsigned char)13, "", prevScreen, GfuiScreenReplace, NULL);

    GfuiMenuDefaultKeysAdd(scrHandle);

    GfuiScreenActivate(scrHandle);

}

