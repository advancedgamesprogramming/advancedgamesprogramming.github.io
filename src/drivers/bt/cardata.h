
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

    file                 : cardata.h
    created              : Thu Sep 23 12:31:33 CET 2004
    copyright            : (C) 2004 Bernhard Wymann
    email                : berniw@bluewin.ch
    version              : $Id: cardata.h,v 1.2 2006/03/06 22:43:50 berniw Exp $

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
	This class holds global facts about cars, therefore no data relative to
	each other (for that is the class Opponents/Opponent responsible).
*/

#ifndef _BT_CARDATA_H_
#define _BT_CARDATA_H_

#include <stdio.h>
#include <math.h>
#include <car.h>
#include <robottools.h>
#include <raceman.h>



class SingleCardata {
	public:
		inline void init(CarElt *car) { this->car = car; /*teammate = false; teammatedamage = 0; */}

		inline float getSpeedInTrackDirection() { return speed; }
		inline float getWidthOnTrack() { return width; }
		inline float getTrackangle() { return trackangle; }
		inline float getCarAngle() { return angle; }

		inline bool thisCar(tCarElt *car) { return (car == this->car); }

		void update();

	protected:
		static float getSpeed(tCarElt *car, float trackangle);

		float speed;		// speed in direction of the track.
		float width;		// the cars needed width on the track.
		float trackangle;	// Track angle at the opponents position.
		float angle;		// The angle of the car relative to the track tangent.

		tCarElt *car;		// For identification.
};


// TODO: use singleton pattern.
class Cardata {
	public:
		Cardata(tSituation *s);
		~Cardata();

		void update();
		SingleCardata *findCar(tCarElt *car);

	protected:
		SingleCardata *data;	// Array with car data.
		int ncars;				// # of elements in data.
};


#endif // _BT_CARDATA_H_
