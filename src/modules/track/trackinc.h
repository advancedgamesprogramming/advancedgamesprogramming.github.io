
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

    file                 : trackinc.h
    created              : Sun Jan 30 22:57:40 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: trackinc.h,v 1.4 2002/05/19 12:16:37 torcs Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
 
 
#ifndef _TRACKINC_H__
#define _TRACKINC_H__


extern void TrackShutdown(void);
extern void ReadTrack3(tTrack *theTrack, void *TrackHandle, tRoadCam **camList, int ext);
extern void ReadTrack4(tTrack *theTrack, void *TrackHandle, tRoadCam **camList, int ext);

extern tTrack *TrackBuildv1(char *trackfile);
extern tTrack *TrackBuildEx(char *trackfile);
extern tdble TrackHeightG(tTrackSeg *seg, tdble x, tdble y);
extern tdble TrackHeightL(tTrkLocPos *p);
extern void TrackGlobal2Local(tTrackSeg *segment, tdble X, tdble Y, tTrkLocPos *p, int sides);
extern void TrackLocal2Global(tTrkLocPos *p, tdble *X, tdble *Y);
extern void TrackSideNormal(tTrackSeg*, tdble, tdble, int, t3Dd*);
extern void TrackSurfaceNormal(tTrkLocPos *p, t3Dd *norm);
extern tRoadCam *TrackGetCamList(void);
extern tdble TrackSpline(tdble p0, tdble p1, tdble t0, tdble t1, tdble t);


#endif /* _TRACKINC_H__ */ 



