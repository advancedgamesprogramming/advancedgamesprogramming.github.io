
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

    file        : raceresults.h
    created     : Thu Jan  2 12:43:28 CET 2003
    copyright   : (C) 2002-2014 by Eric Espie, Bernhard Wymann
    email       : eric.espie@torcs.org   
    version     : $Id: raceresults.h,v 1.3.2.2 2014/02/04 14:02:37 berniw Exp $                                  

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
    @version	$Id: raceresults.h,v 1.3.2.2 2014/02/04 14:02:37 berniw Exp $
*/

#ifndef _RACERESULTS_H_
#define _RACERESULTS_H_


extern void ReInitResults(void);
extern void ReStoreRaceResults(const char *race);
extern int  ReDisplayResults(void);
extern void ReDisplayStandings(void);
extern void ReSavePracticeLap(tCarElt *car);
extern void ReUpdateQualifCurRes(tCarElt *car);
extern void ReEventInitResults(void);
extern void ReUpdateStandings();

#endif /* _RACERESULTS_H_ */ 


