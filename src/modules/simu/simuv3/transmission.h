
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

    file                 : transmission.h
    created              : Mon Apr 16 16:04:36 CEST 2001
    copyright            : (C) 2001 by Eric Espié
    email                : Eric.Espie@torcs.org
    version              : $Id: transmission.h,v 1.19 2005/04/04 14:56:37 olethros Exp $

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
    @version	$Id: transmission.h,v 1.19 2005/04/04 14:56:37 olethros Exp $
*/

#ifndef _TRANSMISSION_H_
#define _TRANSMISSION_H_

typedef struct 
{
    int		gear;
    int		gearMin;
    int		gearMax;
} tGearbox;

typedef struct
{
    int		state;
#define CLUTCH_APPLIED	 1
#define CLUTCH_RELEASED  0
#define CLUTCH_RELEASING 2
    int		mode;
#define CLUTCH_AUTO	0
#define CLUTCH_MANUAL	1
    tdble	timeToRelease;	/* remaining time before releasing the clutch pedal */
    tdble	releaseTime;	/* time needed for releasing the clutch pedal */
    tdble	transferValue;	/* 1.0 -> released, 0.0 -> applied */
    tdble	plip;		/* automatic plip... */
} tClutch;

typedef struct
{
    tGearbox	gearbox;
    tClutch	clutch;
    int		type;
#define TRANS_RWD	0
#define TRANS_FWD	1
#define TRANS_4WD	2
    tdble	overallRatio[MAX_GEARS];	/* including final drive ratio */
    tdble	driveI[MAX_GEARS];		/* Inertia (including engine) */
    tdble	freeI[MAX_GEARS];		/* Inertia when clutch is applied (wheels side) */
    tdble	gearEff[MAX_GEARS];		/* Gear Efficiency */
    tdble	curOverallRatio;
    tdble	curI;

#define TRANS_FRONT_DIFF	0
#define TRANS_REAR_DIFF		1
#define TRANS_CENTRAL_DIFF	2
    tDifferential	differential[3];
} tTransmission;


#endif /* _TRANSMISSION_H_ */ 



