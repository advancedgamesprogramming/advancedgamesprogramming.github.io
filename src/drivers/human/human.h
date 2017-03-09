
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

    file        : human.h
    created     : Sat May 10 19:12:46 CEST 2003
    copyright   : (C) 2003 by Eric Espi�                        
    email       : eric.espie@torcs.org   
    version     : $Id: human.h,v 1.3.2.3 2013/08/29 20:03:44 berniw Exp $                                  

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
    @version	$Id: human.h,v 1.3.2.3 2013/08/29 20:03:44 berniw Exp $
*/

#ifndef _HUMAN_H_
#define _HUMAN_H_

typedef struct HumanContext
{
	int		NbPitStops;
	int		LastPitStopLap;
	int 	AutoReverseEngaged;
	tdble	Gear;
	tdble	distToStart;
	tdble	clutchtime;
	tdble	clutchdelay;
	tdble	ABS;
	tdble	AntiSlip;
	int		lap;
	tdble	prevLeftSteer;
	tdble	prevRightSteer;
	tdble	paccel;
	tdble	pbrake;
	int		manual;
	int		Transmission;
	int		NbPitStopProg;
	int		ParamAsr;
	int		ParamAbs;
	int		RelButNeutral;
	int		SeqShftAllowNeutral;
	int		AutoReverse;
	int		drivetrain;
	int		autoClutch;
	tControlCmd	*CmdControl;
	int		MouseControlUsed;
	int		lightCmd;
} tHumanContext;


extern tHumanContext *HCtx[];

extern int joyPresent;

#endif /* _HUMAN_H_ */ 



