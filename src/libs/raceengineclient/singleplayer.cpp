
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

    file        : singleplayer.cpp
    created     : Sat Nov 16 09:36:29 CET 2002
    copyright   : (C) 2002 by Eric Espié                        
    email       : eric.espie@torcs.org   
    version     : $Id: singleplayer.cpp,v 1.4 2004/04/05 18:25:00 olethros Exp $                                  

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
    		
    @author	<a href=mailto:eric.espie@torcs.org>Eric Espie</a>
    @version	$Id: singleplayer.cpp,v 1.4 2004/04/05 18:25:00 olethros Exp $
*/

#include <stdlib.h>
#include <stdio.h>
#include <tgfclient.h>
#include <raceman.h>

#include "raceengine.h"
#include "racemain.h"
#include "raceinit.h"
#include "racestate.h"

static void *singlePlayerHandle = NULL;

/* Called when the menu is activated */
static void
singlePlayerMenuActivate(void * /* dummy */)
{
    /* Race engine init */
    ReInit();
    ReInfo->_reMenuScreen = singlePlayerHandle;
}

/* Exit from Race engine */
static void
singlePLayerShutdown(void *precMenu)
{
    GfuiScreenActivate(precMenu);
    ReShutdown();
}


/* Initialize the single player menu */
void *
ReSinglePlayerInit(void *precMenu)
{
    if (singlePlayerHandle) return singlePlayerHandle;
    
    singlePlayerHandle = GfuiScreenCreateEx((float*)NULL, 
					    NULL, singlePlayerMenuActivate, 
					    NULL, (tfuiCallback)NULL, 
					    1);

    GfuiTitleCreate(singlePlayerHandle, "SELECT RACE", 0);

    GfuiScreenAddBgImg(singlePlayerHandle, "data/img/splash-single-player.png");

    /* Display the raceman button selection */
    ReAddRacemanListButton(singlePlayerHandle);

    GfuiMenuDefaultKeysAdd(singlePlayerHandle);

    ReStateInit(singlePlayerHandle);

    GfuiMenuBackQuitButtonCreate(singlePlayerHandle,
				 "Back", "Back to Main",
				 precMenu, singlePLayerShutdown);
    
    return singlePlayerHandle;
}
