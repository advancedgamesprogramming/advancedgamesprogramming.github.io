
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

/* -*- Mode: c++ -*- */
/* VER: $Id: MathFunctions.h,v 1.3 2005/08/05 09:02:58 berniw Exp $ */
// copyright (c) 2004 by Christos Dimitrakakis <dimitrak@idiap.ch>
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef MATH_FUNCTIONS_H
#define MATH_FUNCTIONS_H

#include <learning/real.h>

extern int ArgMin (int n, real* x);
extern int ArgMax (int n, real* x);
extern real SmoothMaxGamma (real f1, real f2, real lambda, real c);
extern real SmoothMaxPNorm (real f1, real f2, real p);
extern void SoftMax (int n, real* Q, real* p, real beta);
extern void SoftMin (int n, real* Q, real* p, real beta);
extern void Normalise (real* src, real* dst, int n_elements);
extern real EuclideanNorm (real* a, real* b, int n);
extern real SquareNorm (real* a, real* b, int n);
extern real LNorm (real* a, real* b, int n, real p);
extern real Sum (real* a, int n);

template<class T>
inline const T sign(const T& x)
{
	if (x>0) {
		return 1;
	} else if (x<0) {
		return -1;
	} else {
		return 0;
	}
} 

#endif
