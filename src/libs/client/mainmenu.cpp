
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

    file                 : mainmenu.cpp
    created              : Sat Mar 18 23:42:38 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: mainmenu.cpp,v 1.4.2.1 2008/08/16 23:59:54 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/


#include <stdio.h>
#include <tgfclient.h>
#include <singleplayer.h>
#include <driverconfig.h>

#include "mainmenu.h"
#include "exitmenu.h"
#include "optionmenu.h"


void *menuHandle = NULL;
tModList *RacemanModLoaded = (tModList*)NULL;

static void
TorcsMainMenuActivate(void * /* dummy */)
{
	if (RacemanModLoaded != NULL) {
		GfModUnloadList(&RacemanModLoaded);
	}
}

/*
 * Function
 *	TorcsMainMenuInit
 *
 * Description
 *	init the main menus
 *
 * Parameters
 *	none
 *
 * Return
 *	0 ok -1 nok
 *
 * Remarks
 *	
 */
int
TorcsMainMenuInit(void)
{
    menuHandle = GfuiScreenCreateEx((float*)NULL, 
				    NULL, TorcsMainMenuActivate, 
				    NULL, (tfuiCallback)NULL, 
				    1);

    GfuiScreenAddBgImg(menuHandle, "data/img/splash-main.png");

    GfuiTitleCreate(menuHandle, "TORCS", 0);

    GfuiLabelCreate(menuHandle,
		    "The Open Racing Car Simulator",
		    GFUI_FONT_LARGE,
		    320,
		    420,
		    GFUI_ALIGN_HC_VB,
		    0);

    GfuiMenuButtonCreate(menuHandle,
			 "Race", "Races Menu",
			 ReSinglePlayerInit(menuHandle), GfuiScreenActivate);

    GfuiMenuButtonCreate(menuHandle,
			 "Configure Players", "Players configuration menu",
			 TorcsDriverMenuInit(menuHandle), GfuiScreenActivate);

    GfuiMenuButtonCreate(menuHandle,
			 "Options", "Configure",
			 TorcsOptionOptionInit(menuHandle), GfuiScreenActivate);
    
    GfuiMenuDefaultKeysAdd(menuHandle);

    GfuiMenuBackQuitButtonCreate(menuHandle,
				 "Quit", "Quit TORCS",
				 TorcsMainExitMenuInit(menuHandle), GfuiScreenActivate);

    return 0;
}

/*
 * Function
 *	
 *
 * Description
 *	
 *
 * Parameters
 *	
 *
 * Return
 *	
 *
 * Remarks
 *	
 */
int
TorcsMainMenuRun(void)
{
    GfuiScreenActivate(menuHandle);
    return 0;
}
