
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
                        Os.h --- os specific functions interface                                
                             -------------------                                         
    created              : Fri Aug 13 22:27:29 CEST 1999
    copyright            : (C) 1999 by Eric Espie                         
    email                : torcs@free.fr   
    version              : $Id: os.h,v 1.2.2.1 2008/12/31 03:53:55 berniw Exp $                                  
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
 
#ifndef _OS__H_
#define _OS__H_

#include <tgf.h>
     
/* dynamic module (dll) interfaces */
typedef int (*tfModLoad)(unsigned int, char*, tModList **);
typedef int (*tfModLoadDir)(unsigned int, char*, tModList **);
typedef int (*tfModUnloadList)(tModList **);
typedef int (*tfModGetInfo)(unsigned int, char*, tModList **);
typedef int (*tfModGetInfoDir)(unsigned int, char*, int, tModList **);
typedef int (*tfModFreeInfoList)(tModList **);
/* directory interface */
typedef tFList *(*tfDirGetList)(const char *);
typedef tFList *(*tfDirGetListFiltered)(const char *, const char *);
/* time interface */
typedef double (*tfTimeClock)(void);

typedef struct {
   // tfModLoad			modLoad;
    tfModLoadDir		modLoadDir;
    tfModUnloadList		modUnloadList;
    tfModGetInfo		modInfo;
    tfModGetInfoDir		modInfoDir;
    tfModFreeInfoList		modFreeInfoList;
    tfDirGetList		dirGetList;
    tfDirGetListFiltered	dirGetListFiltered;
    tfTimeClock			timeClock;
} tGfOs;

#ifdef WIN32
#ifdef TGF_EXPORTS
__declspec(dllexport)
#else // TGF_EXPORTS
__declspec(dllimport)
#endif // TGF_EXPORTS
#endif // WIN32
extern tGfOs GfOs;

#endif /* _OS__H_ */
