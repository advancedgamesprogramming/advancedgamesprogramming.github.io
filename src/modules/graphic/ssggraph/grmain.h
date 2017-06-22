
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

    file                 : grmain.h
    created              : Fri Aug 18 00:00:41 CEST 2000
    copyright            : (C) 2000-2013 by Eric Espie, Bernhard Wymann
    email                : torcs@free.fr
    version              : $Id: grmain.h,v 1.18.2.2 2013/09/01 10:24:22 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

 
#ifndef _GRMAIN_H_
#define _GRMAIN_H_

#include <config.h>

#include <plib/ssg.h>
#include <raceman.h>

#ifdef WIN32
#include <windows.h>

#if HAVE_GL
#include <GL/gl.h>
#include <GL/glext.h>
#endif


#if HAVE_GL
////// Multitexturing Info
extern PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB ;
extern PFNGLMULTITEXCOORD2FVARBPROC glMultiTexCoord2fvARB;
extern PFNGLACTIVETEXTUREARBPROC   glActiveTextureARB ;
extern PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTextureARB ;
#endif

extern bool InStr(char *searchStr, char *str);
#endif

extern bool InitMultiTex();
extern int grWinx, grWiny, grWinw, grWinh;

extern int grVectFlag;
extern int grVectDispFlag[];
extern int segIndice;

extern double grCurTime;

extern void *grHandle;
extern void *grTrackHandle;

extern ssgContext grContext;
extern int grNbCars;

extern int  initView(int x, int y, int width, int height, int flag, void *screen);
extern int  initCars(tSituation *s);
extern int  refresh(tSituation *s);
extern void shutdownCars(void);
extern int  initTrack(tTrack *track);
extern void shutdownTrack(void);
extern void muteForMenu(void);
//extern void bendCar (int index, sgVec3 poc, sgVec3 force, int cnt);
extern int maxTextureUnits;
extern tdble grMaxDammage;

extern class cGrScreen *grScreens[];

#define GR_SPLIT_ADD	0
#define GR_SPLIT_REM	1

#define GR_NB_MAX_SCREEN 4

extern tdble grLodFactorValue;
extern double grDeltaTime;

enum EWheelDetail { DETAILED, SIMPLE };
extern EWheelDetail grUseDetailedWheels;

inline float urandom() {
	return (((float)rand()/(1.0+(float)RAND_MAX)));
}


#endif /* _GRMAIN_H_ */ 



