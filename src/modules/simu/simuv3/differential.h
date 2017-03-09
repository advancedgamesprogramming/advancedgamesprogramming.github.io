
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

    file                 : differential.h
    created              : Sun Mar 19 00:06:46 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: differential.h,v 1.21 2006/06/18 09:29:42 olethros Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef _DIFFERENTIAL_H_
#define _DIFFERENTIAL_H_

typedef struct
{
    tdble	spinVel;
    tdble	Tq;
    tdble	brkTq;
    tdble	I;
} tDynAxis;

typedef struct
{
    /* caracteristics */
    int		type;
#define DIFF_NONE		0
#define DIFF_SPOOL		1
#define DIFF_FREE		2
#define DIFF_LIMITED_SLIP	3
#define DIFF_VISCOUS_COUPLER	4
#define DIFF_LOCKING            5
    tdble	ratio;
    tdble	I;
    tdble	efficiency;
    tdble	bias;
    tdble	dTqMin;
    tdble	dTqMax;
    tdble	dSlipMax;
    tdble	lockInputTq;
    tdble	viscosity;
    tdble	viscomax;

    /* dynamic data */
    tDynAxis	in;
    tDynAxis	feedBack;
    tDynAxis	*inAxis[2];
    tDynAxis	*outAxis[2];
} tDifferential;



#endif /* _DIFFERENTIAL_H_ */ 



