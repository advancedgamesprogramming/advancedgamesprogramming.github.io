
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

    file                 : spline.h
    created              : Mon Apr 17 13:51:00 CET 2000
    copyright            : (C) 2000-2002 by Bernhard Wymann
    email                : berniw@bluewin.ch
    version              : $Id: spline.h,v 1.1 2004/01/20 13:45:23 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef _SPLINE_H_
#define _SPLINE_H_

// Structs to arrange data cache-friendly.
typedef struct {
	double a, b, c, d, h;
} SplineEquationData;

typedef struct {
	double a, b, c, d, h, x1, x2;
} SplineEquationData2;


/* solves tridiagonal matrix in linear time O(n) with Given's Rotations */
extern void tridiagonal(int dim, SplineEquationData *tmp, double *x);


/* solving tridiagonal nxn matrix for two vectors with Givens-Rotations in linear time O(n) */
extern void tridiagonal2(int dim, SplineEquationData2 *tmp);


/* compute the slopes of the spline points with periodic constraints */
extern void slopesp(int dim, const double *const x, const double *const y, double *const ys);


/* compute the slopes of the spline points with natural constraints */
extern void slopesn(int dim, const double *const x, const double *const y, double *const ys);


/* compute the slopes for 2-dim curve, sums euclidian distances as parameter, periodic */
extern void parametricslopesp(
	int dim,
	const double *const x,
	const double *const y,
	double *const xs,
	double *const ys,
	double *const s
);


/* compute the slopes for 2-dim curve, sums euclidian distances as parameter, natural */
extern void parametricslopesn(
	int dim,
	const double *const x,
	const double *const y,
	double *const xs,
	double *const ys,
	double *const s
);


/* compute the y value for a given z */
extern double spline(
	int dim,
	double z,
	const double *const x,
	const double *const y,
	const double *const ys
);


#endif // _SPLINE_H_

