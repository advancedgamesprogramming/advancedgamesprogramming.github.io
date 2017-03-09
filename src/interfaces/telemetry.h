
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

    file                 : telemetry.h
    created              : Sun Jan 30 22:59:54 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: telemetry.h,v 1.3 2004/10/07 17:05:04 olethros Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
 
 
#ifndef _TELEMETRY_H_
#define _TELEMETRY_H_

#define TLM_IDENT	1

#include <tgf.h>

typedef void(*tftlmInit)(tdble /* ymin */, tdble /* ymax */);
typedef void(*tftlmNewChannel)(const char * /* name */, tdble * /* var */, tdble /* min */, tdble /* max */);
typedef void(*tftlmStartMonitoring)(const char * /* filename */);
typedef void(*tftlmStopMonitoring)(void);
typedef void(*tftlmUpdate)(double /* time */);
typedef void(*tftlmShutdown)(void);


typedef struct 
{
    tftlmInit			init;			/* Init the telemetry */
    tftlmNewChannel		newChannel;		/* Create a new channel */
    tftlmStartMonitoring	startMonitoring;	/* Start monitoring */
    tftlmStopMonitoring		stopMonitoring;		/* Stop monitoring */
    tftlmUpdate			update;			/* Update telemetry */
    tftlmShutdown		shutdown;		/* close the telemetry */
} tTelemItf;



#endif /* _TELEMETRY_H_ */ 



