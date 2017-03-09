
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

    file                 : trackgen.h
    created              : Sun Dec 24 16:00:03 CET 2000
    copyright            : (C) 2000 by Eric Espié
    email                : Eric.Espie@torcs.org
    version              : $Id: trackgen.h,v 1.7.2.2 2012/09/05 16:08:04 berniw Exp $

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
    @version	$Id: trackgen.h,v 1.7.2.2 2012/09/05 16:08:04 berniw Exp $
*/

#ifndef _TRACKGEN_H_
#define _TRACKGEN_H_

#define CLOCKWISE	0
#define ANTICLOCKWISE	1

#define CFG_FILE	"tools/trackgen/trackgen.xml"


extern void GenerateTrack(tTrack * Track, void *TrackHandle, char *outFile, FILE *AllFd, int bump, int raceline);
extern void CalculateTrack(tTrack * Track, void *TrackHandle);
extern void generateRaceLine(tTrack *pTrack, const double SideDistExt, const double SideDistInt);
extern double getTexureOffset(double length);

extern char	*OutputFileName;
extern int	HeightSteps;
extern int	UseBorder;

#endif /* _TRACKGEN_H_ */ 



