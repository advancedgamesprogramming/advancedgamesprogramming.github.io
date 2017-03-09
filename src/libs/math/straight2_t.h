
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

    file                 : straight2_t.h
    created              : Due Apr 5 13:51:00 CET 2005
    copyright            : (C) 2005 by Bernhard Wymann
    email                : berniw@bluewin.ch
    version              : $Id: straight2_t.h,v 1.2 2005/08/05 09:04:53 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

/*
	Template for 2d-straight, to be used with float or double 2-d vectors. This template is NOT
	intended to work with classes which allocate memory. Be aware that there are more
	efficient methods for doing most of the operations (avoiding temp verctors and make
	better use of registers). Later I will try to improve the performance (SSE,
	"abuse" of templates to avoid temporaries).
*/


#ifndef _STRAIGHT_2T_H_
#define _STRAIGHT_2T_H_

#include <tmath/v2_t.h>

template<class T> class straight2t {
	public:
		// Constructors.
		straight2t() {}
		straight2t(T x, T y, T dx, T dy)
			{ p.x = x; p.y = y; d.x = dx; d.y = dy; d.normalize(); }
		straight2t(const v2t<T> &anchor, const v2t<T> &dir)
			{ p = anchor; d = dir; d.normalize(); }

		// Methods.
		v2t<T> intersect(const straight2t<T> &s) const;		// Intersection of 2 straights: does not check for NaN's!
		T dist(const v2t<T> &p) const;						// Distance of p to straight this.

		// Data.
		v2t<T> p;	// Point on the straight.
		v2t<T> d;	// Direction of the straight.
};


// intersection point of *this and s
template<class T> inline v2t<T> straight2t<T>::intersect(const straight2t<T> &s) const
{
    T t = -(d.x*(s.p.y-p.y)+d.y*(p.x-s.p.x))/(d.x*s.d.y-d.y*s.d.x);
    return s.p + s.d*t;
}


// distance of point s from straight *this
template<class T> inline T straight2t<T>::dist(const v2t<T> &s) const
{
    v2t<T> d1 = s - p;
    v2t<T> d3 = d1 - d*d1*d;
    return d3.len();
}

#endif //_STRAIGHT_2T_H_


