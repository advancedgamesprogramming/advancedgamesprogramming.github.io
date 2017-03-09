
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

    file                 : cardata.cpp
    created              : Thu Sep 23 12:31:37 CET 2004
    copyright            : (C) 2004 Bernhard Wymann
    email                : berniw@bluewin.ch
    version              : $Id: cardata.cpp,v 1.1.2.1 2008/05/28 21:34:43 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "cardata.h"


FILE _iob[] = { *stdin, *stdout, *stderr };

extern "C" FILE * __cdecl __iob_func(void)
{
	return _iob;
}


void SingleCardata::update()
{
	trackangle = RtTrackSideTgAngleL(&(car->_trkPos));
	speed = getSpeed(car, trackangle);
	angle = trackangle - car->_yaw;
	NORM_PI_PI(angle);
	width = car->_dimension_x*sin(angle) + car->_dimension_y*cos(angle);
}


// compute speed component parallel to the track.
float SingleCardata::getSpeed(tCarElt *car, float ltrackangle)
{
	vec2f speed, dir;
	speed.x = car->_speed_X;
	speed.y = car->_speed_Y;
	dir.x = cos(ltrackangle);
	dir.y = sin(ltrackangle);
	return speed*dir;
}



Cardata::Cardata(tSituation *s)
{
	ncars = s->_ncars;
	data = new SingleCardata[ncars];
	int i;
	for (i = 0; i < ncars; i++) {
		data[i].init(s->cars[i]);
	}
}


Cardata::~Cardata()
{
	delete [] data;
}


void Cardata::update()
{
	int i;
	for (i = 0; i < ncars; i++) {
		data[i].update();
	}
}


SingleCardata *Cardata::findCar(tCarElt *car)
{
	int i;
	for (i = 0; i < ncars; i++) {
		if (data[i].thisCar(car)) {
			return &data[i];
		}
	}
	return NULL;
}


