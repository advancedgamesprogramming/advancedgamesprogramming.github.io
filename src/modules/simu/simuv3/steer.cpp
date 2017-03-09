
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

    file                 : steer.cpp
    created              : Sun Mar 19 00:08:20 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: steer.cpp,v 1.21 2005/08/30 15:29:51 olethros Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "sim.h"

void 
SimSteerConfig(tCar *car)
{
    void *hdle = car->params;

    car->steer.steerLock = GfParmGetNum(hdle, SECT_STEER, PRM_STEERLOCK, (char*)NULL, 0.43);
    car->steer.maxSpeed  = GfParmGetNum(hdle, SECT_STEER, PRM_STEERSPD, (char*)NULL, 1.0);
    car->carElt->_steerLock = car->steer.steerLock;
}


void 
SimSteerUpdate(tCar *car)
{
    tdble steer, steer2;
    tdble stdelta;
    tdble tanSteer;

    /* input control */
    steer = car->ctrl->steer;
    steer *= car->steer.steerLock;
    stdelta = steer - car->steer.steer;
    
    if ((fabs(stdelta) / SimDeltaTime) > car->steer.maxSpeed) {
		steer = SIGN(stdelta) * car->steer.maxSpeed * SimDeltaTime + car->steer.steer;
    }
    car->steer.steer = steer;

	tanSteer = fabs(tan(steer));
	steer2 = atan2(car->wheelbase * tanSteer ,(car->wheelbase - tanSteer * car->wheeltrack));

	
	//printf ("%f %f\n", steer2, steer);
    if (steer > 0) {
		car->wheel[FRNT_RGT].steer = steer2;
		car->wheel[FRNT_LFT].steer = steer;
    } else {
		car->wheel[FRNT_RGT].steer = steer;
		car->wheel[FRNT_LFT].steer = -steer2;
    }
}

	
