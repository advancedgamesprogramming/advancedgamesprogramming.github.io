
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

    file        : portability.h
    created     : Fri Jul 8 15:19:34 CET 2005
    copyright   : (C) 2005 Bernhard Wymann
    email       : berniw@bluewin.ch
    version     : $Id: portability.h,v 1.2.2.3 2012/05/19 14:47:30 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef _TORCS_PORTABILITY_H_
#define _TORCS_PORTABILITY_H_

#include <stdlib.h>
#include <cstring>

#ifdef WIN32
#define HAVE_CONFIG_H
#endif

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

// Missing strndup, define it here (for FreeBSD).
// TODO: Move it into library.
// strndup code provided by Thierry Thomas.
#ifndef HAVE_STRNDUP

static char *strndup(const char *str, int len)
{
	char *ret;

	if ((str == NULL || len < 0)) {
		return (NULL);
	}

	ret = (char *) malloc(len + 1);
	if (ret == NULL) {
		return (NULL);
	}

	memcpy(ret, str, len);
	ret[len] = '\0';
	return (ret);
}

#endif

#include <stdio.h>
extern "C" FILE * __cdecl __iob_func(void);

//static
//FILE _iob[] = { *stdin, *stdout, *stderr };
//
//extern "C" 
//inline FILE * __cdecl __iob_func(void)
//{
//	return _iob;
//}
#ifdef WIN32
//#define snprintf _snprintf
#if _MSC_VER < 1500 
#define vsnprintf _vsnprintf
#endif
#endif

#ifdef WIN32
#include <math.h>

#if 0
static float round(float x)
{
	return floor(x+0.5f);
}
#endif

#endif 

#endif // _TORCS_PORTABILITY_H_

