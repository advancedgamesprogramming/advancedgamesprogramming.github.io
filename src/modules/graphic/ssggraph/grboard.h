
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

    file                 : grboard.h
    created              : Thu Aug 17 23:55:47 CEST 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: grboard.h,v 1.9.2.1 2008/12/31 03:53:56 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef _GRBOARD_H_
#define _GRBOARD_H_

#include <raceman.h>
#include "grtrackmap.h"

class cGrBoard
{
 protected:
    int	id;		/* Board Id */

    int	boardFlag;

    int leaderFlag;
    int debugFlag;
    int leaderNb;
    int counterFlag;
    int GFlag;
    int arcadeFlag;

 private:
    void grDispDebug(float fps, tCarElt *car);
    void grDispGGraph(tCarElt *car);
    void grDispCarBoard1(tCarElt *car, tSituation *s);
    void grDispMisc(tCarElt *car);
    void grDrawGauge(tdble X1, tdble Y1, tdble H, float *clr1, float *clr2, tdble val, const char *title);
    void grDispCarBoard2(tCarElt *car, tSituation *s);
    void grDispCarBoard(tCarElt *car, tSituation *s);
    void grDispCounterBoard(tCarElt *car);
    void grDispLeaderBoard(tCarElt *car, tSituation *s);
    void grDispCounterBoard2(tCarElt *car);
    void grDispArcade(tCarElt *car, tSituation *s);

	// Track overview object
	cGrTrackMap *trackMap;

 public:
    cGrBoard(int myid);
	~cGrBoard();

    void initBoard(void);
    void shutdown(void);
    void selectBoard(int brd);
	void dispGaph(tCarElt *car) {};
	void initBoardCar(tCarElt *car) {};
	cGrTrackMap *getTrackMap() { return trackMap; }

    void refreshBoard(tSituation *s, float Fps, int forceArcade, tCarElt *curr);
    void loadDefaults(tCarElt *curCar);
};

extern void grInitBoardCar(tCarElt *car);
extern void grShutdownBoardCar(void);

#endif /* _GRBOARD_H_ */ 



