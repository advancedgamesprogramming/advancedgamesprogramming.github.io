
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

    file                 : linalg_t.h
    created              : Mo Mar 11 13:51:00 CET 2002
    copyright            : (C) 2002-2005 by Bernhard Wymann
    email                : berniw@bluewin.ch
    version              : $Id: linalg_t.h,v 1.2.2.1 2012/10/09 11:19:55 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef _LINALG_T_H_
#define _LINALG_T_H_

#include <math.h>
#include <tmath/v2_t.h>
#include <tmath/v3_t.h>
#include <tmath/v4_t.h>

#include <tmath/straight2_t.h>

typedef v4t<float> vec4f;
typedef v4t<double> vec4d;

typedef v3t<float> vec3f;
typedef v3t<double> vec3d;

typedef v2t<float> vec2f;
typedef v2t<double> vec2d;

typedef straight2t<float> straight2f;
typedef straight2t<double> straight2d;

#endif // _LINALG_T_H_

