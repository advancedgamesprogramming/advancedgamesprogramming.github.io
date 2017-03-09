
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

    file                 : wheel.h
    created              : Sun Mar 19 00:09:18 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: wheel.h,v 1.7.2.1 2013/08/04 11:20:57 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef _WHEEL_H__
#define _WHEEL_H__

#include "differential.h"

typedef struct
{

    /* internal data */
    tSuspension  susp;		/* associated suspension */
    tBrake       brake;		/* associated brake disk */

    /* dynamic */
    t3Dd	forces;		/* forces acting on car */
    tdble	rollRes;	/* Rolling Resistance (summed over the car) */
    tdble	rideHeight;	/* height of the bottom of the car */
    tdble	zRoad;		/* z of the road */
    t3Dd   	pos;	   	/* world related */
    t3Dd	bodyVel;	/* world related */
    tdble  	driveTq;   	/* engine torque */
    tdble	vt;

    tdble  	spinTq;		/* spin torque feedback */
    tdble  	spinVel;   	/* spin velocity */
    tdble  	prespinVel;   	/* spin velocity */
    int     	state;     	/* wheel state */
    /* 1 and 2 are for suspension state */
#define SIM_WH_ONAIR 4	/* the wheel has no contact to the ground although the suspension is not fully extended */
    tdble	axleFz;		/* force from axle (anti-roll bar) */
    tTrkLocPos	trkPos;		/* current track position */
    tPosd	relPos;		/* relative pos / GC */
    tdble	sa;		/* slip angle */
    tdble	sx;		/* longitudinal slip value */
    tdble	steer;
    
    /* static */
    tPosd	staticPos;	/* pos relative to the GC (z is suspension travel at rest) */
				/* and angles are camber (ax), caster (ay) and toe (az) */
    tdble	rollCenter;

    tdble  	weight0;	/* initial weight on this wheel */
    tdble	tireSpringRate;
    tdble  	radius;
    tdble  	mu;
    tdble  	I;       	/* I = inertial moment of the wheel */
    tdble  	curI;       	/* Current inertia for the wheel (including transmission) */
    tdble	mfC;		/* Magic Formula C coeff */
    tdble	mfB;		/* Magic Formula B coeff */
    tdble	mfE;		/* Magic Formula E coeff */
    tdble	lfMax;		/* Load factor */
    tdble	lfMin;		/* Load factor */
    tdble	lfK;		/* Load factor */
    tdble	opLoad;		/* Operating load */
    tdble	mass;		/* total wheel mass (incl. brake) (unsprung mass) */
    tdble	camber;		/* camber, negative toward exterior on both sides */
    tdble	pressure;	/* tire pressure */
	tdble   rel_vel;    /* relative velocity - used for realstic suspension movement*/

    tDynAxis	in;
    tDynAxis	feedBack;

    tdble	preFn, preFt;
} tWheel;

    

#endif /* _WHEEL_H__ */ 



