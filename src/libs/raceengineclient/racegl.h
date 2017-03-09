
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

    file        : racegl.h
    created     : Sat Nov 16 19:02:56 CET 2002
    copyright   : (C) 2002 by Eric Espi�                        
    email       : eric.espie@torcs.org   
    version     : $Id: racegl.h,v 1.3.2.1 2008/12/31 03:53:55 berniw Exp $                                  

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
    @version	$Id: racegl.h,v 1.3.2.1 2008/12/31 03:53:55 berniw Exp $
*/

#ifndef _RACEGL_H_
#define _RACEGL_H_

extern void *ReScreenInit(void);
extern void  ReScreenShutdown(void);
extern void *ReHookInit(void);
extern void ReHookShutdown(void);
extern void ReSetRaceMsg(const char *msg);
extern void ReSetRaceBigMsg(const char *msg);

extern void *ReResScreenInit(void);
extern void ReResScreenSetTitle(char *title);
extern void ReResScreenAddText(char *text);
extern void ReResScreenSetText(const char *text, int line, int clr);
extern void ReResScreenRemoveText(int line);
extern void ReResShowCont(void);
extern int  ReResGetLines(void);
extern void ReResEraseScreen(void);

#endif /* _RACEGL_H_ */ 



