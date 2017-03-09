
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

    file        : raceinit.h
    created     : Sat Nov 16 12:24:26 CET 2002
    copyright   : (C) 2002 by Eric Espi�                        
    email       : eric.espie@torcs.org   
    version     : $Id: raceinit.h,v 1.4.2.2 2012/02/14 23:42:20 berniw Exp $                                  

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
    		
    @author	<a href=mailto:torcs@free.fr>Eric Espie</a>
    @version	$Id: raceinit.h,v 1.4.2.2 2012/02/14 23:42:20 berniw Exp $
*/

#ifndef _RACEINIT_H_
#define _RACEINIT_H_

#define RACE_ENG_CFG	"data/config/raceengine.xml"

extern void ReInit(void);
extern void ReShutdown(void);
extern void ReStartNewRace(void * /* dummy */);
extern void ReAddRacemanListButton(void *menuHandle);
extern int  ReInitCars(void);
extern int  ReInitTrack(void);
extern void ReRaceCleanup(void);
extern void ReRaceCleanDrivers(void);
extern const char *ReGetCurrentRaceName(void);
extern const char *ReGetPrevRaceName(void);
extern void ReRunRaceOnConsole(const char* raceconfig);

extern tModList *ReRaceModList;



#endif /* _RACEINIT_H_ */ 



