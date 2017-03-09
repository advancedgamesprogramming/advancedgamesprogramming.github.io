
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

    file                 : trackutil.cpp
    created              : Sun Jan 30 22:58:00 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: trackutil.cpp,v 1.3 2002/10/13 22:03:38 torcs Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <stdlib.h>
#include <math.h>

#include <tgf.h>
#include <track.h>

#include <robottools.h>

void
TrackLocal2Global(tTrkLocPos *p, tdble *X, tdble *Y)
{
    RtTrackLocal2Global(p, X, Y, TR_TORIGHT);
}


void
TrackGlobal2Local(tTrackSeg *segment, tdble X, tdble Y, tTrkLocPos *p, int type)
{
    RtTrackGlobal2Local(segment, X, Y, p, type);
}
/*
 * Function
 *	
 *
 * Description
 *	
 *
 * Parameters
 *	
 *
 * Return
 *	
 */

tdble
TrackHeightL(tTrkLocPos *p)
{
    return RtTrackHeightL(p);
}

tdble
TrackHeightG(tTrackSeg *seg, tdble x, tdble y)
{
    return RtTrackHeightG(seg, x,  y);
}

void
TrackSideNormal(tTrackSeg *seg, tdble x, tdble y, int side, t3Dd *norm)
{
    RtTrackSideNormalG(seg, x, y, side, norm);
}

void
TrackSurfaceNormal(tTrkLocPos *p, t3Dd *norm)
{
    RtTrackSurfaceNormalL(p, norm);
}

tdble
TrackSpline(tdble p0, tdble p1, tdble t0, tdble t1, tdble t)
{
    tdble t2, t3;
    tdble h0, h1, h2, h3;
    
    t2 = t * t;
    t3 = t * t2;
    h1 = 3 * t2 - 2 * t3;
    h0 = 1 - h1;
    h2 = t3 - 2 * t2 + t;
    h3 = t3 - t2;
    
    return h0 * p0 + h1 * p1 + h2 * t0 + h3 * t1;
}
