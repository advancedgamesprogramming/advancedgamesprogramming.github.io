
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

    file                 : pit.h
    created              : Thu Mai 15 2:41:00 CET 2003
    copyright            : (C) 2003-2004 by Bernhard Wymann
    email                : berniw@bluewin.ch
    version              : $Id: pit.h,v 1.1.2.1 2008/05/28 21:34:45 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef _PIT_H_
#define _PIT_H_

#include "driver.h"
#include "spline.h"

class Driver;

class Pit {
	public:
		Pit(tSituation *s, Driver *driver);
		~Pit();

		void setPitstop(bool pitstop);
		bool getPitstop() { return pitstop; }

		void setInPit(bool inpitlane) { this->inpitlane = inpitlane; }
		bool getInPit() { return inpitlane; }

		float getPitOffset(float offset, float fromstart);

		bool isBetween(float fromstart);
		bool isTimeout(float distance);

		float getNPitStart() { return p[1].x; }
		float getNPitLoc() { return p[3].x; }
		float getNPitEnd() { return p[5].x; }

		float toSplineCoord(float x);

		float getSpeedlimitSqr() { return speedlimitsqr; }
		float getSpeedlimit() { return speedlimit; }
		float getSpeedLimitBrake(float speedsqr);

		void update();

	private:
		tTrack *track;
		tCarElt *car;
		tTrackOwnPit *mypit;			// Pointer to my pit.
		tTrackPitInfo *pitinfo;			// General pit info.

		enum { NPOINTS = 7 };
		SplinePoint p[NPOINTS];			// Spline points.
		Spline *spline;					// Spline.

		bool pitstop;					// Pitstop planned.
		bool inpitlane;					// We are still in the pit lane.
		float pitentry;					// Distance to start line of the pit entry.
		float pitexit;					// Distance to the start line of the pit exit.

		float speedlimitsqr;			// Pit speed limit squared.
		float speedlimit;				// Pit speed limit.
		float pitspeedlimitsqr;			// The original speedlimit squared.

		float pittimer;					// Timer for pit timeouts.

		static const float SPEED_LIMIT_MARGIN;
};

#endif // _PIT_H_


