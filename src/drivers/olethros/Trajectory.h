
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

// -*- Mode: c++ -*-
// copyright (c) 2006 by Christos Dimitrakakis <dimitrak@idiap.ch>
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <list>
#include <vector>
#include "TrackData.h"

class Trajectory
{
 public:
    std::vector<float> w; ///< parameters
    std::vector<float> dw; ///< parameter steps
    std::vector<float> dw2; ///<  parameter gradients
    std::vector<float> accel; ///<  maximum acceleration
    std::vector<int> indices; ///< data indices
    static Point GetPoint (Segment& s, float w);
    void Optimise(SegmentList track, int max_iter, float alpha, const char* fname, bool reset = true);
};

#endif
