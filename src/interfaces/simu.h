
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

    file                 : simu.h
    created              : Sun Jan 30 12:02:05 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: simu.h,v 1.7.2.1 2014/04/12 13:55:33 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
 
 
#ifndef _SIMUV1_H_
#define _SIMUV1_H_

#include <track.h>
#include <raceman.h>

#define SIM_IDENT	0

struct Situation;
struct RmInfo;

typedef void (*tfSimInit)(int, tTrack*, tdble, tdble);
typedef void (*tfSimConfig)(tCarElt*, struct RmInfo*);
typedef void (*tfSimReConfig)(tCarElt*);
typedef void (*tfSimUpdate)(struct Situation*, double, int);
typedef void (*tfSimShutdown)(void);

typedef struct
{
    tfSimInit	  init;
    tfSimConfig   config;
    tfSimReConfig reconfig;
    tfSimUpdate   update;
    tfSimShutdown shutdown;
} tSimItf;



#endif /* _SIMUV1_H_ */ 



