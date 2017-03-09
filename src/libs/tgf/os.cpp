
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
                         os.cpp -- os specific function table                             
                             -------------------                                         
    created              : Fri Aug 13 22:26:42 CEST 1999
    copyright            : (C) 1999 by Eric Espie                         
    email                : torcs@free.fr   
    version              : $Id: os.cpp,v 1.5 2002/10/13 22:03:37 torcs Exp $                                  
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
    @version	$Id: os.cpp,v 1.5 2002/10/13 22:03:37 torcs Exp $
    @ingroup OS
*/
#ifdef WIN32
#include <windows.h>
#endif
#include <tgf.h>
#include "os.h"


/*
 * Globals definitions
 */
#if 0
#ifdef WIN32
__declspec(dllexport)
#endif // WIN32
#endif

tGfOs GfOs = {0};

/** Init of the module */
void
gfOsInit(void)
{
}


/** Get the time in seconds
    @return	Time in seconds since the start of the system
*/
double
GfTimeClock(void)
{
    if (GfOs.timeClock) {
	return GfOs.timeClock();
    } else {
	return 0;
    }
}
