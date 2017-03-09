
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

    file                 : osspec.h
    created              : Sat Mar 18 23:54:47 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: osspec.h,v 1.4 2005/08/05 10:34:47 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

 
#ifndef __OSSPEC__H__
#define __OSSPEC__H__

/* Files Extensions */
#define TRKEXT	"xml"
#define DLLEXT	"dll"
#define PARAMEXT ".xml"

#ifndef _WIN32
#error Hey ! Where is _WIN32 ??
#endif

#include <windows.h>
#include <string.h>
#ifdef _WIN32
//#	pragma warning( disable : 4514 4100 4130 4611 4115 4189 4505 4127 4244 4701 4706 4711 4702)
#	define uint unsigned int
#	define uchar unsigned char
#	define execlp _execlp
#	define strncasecmp strnicmp
#	define strcasecmp stricmp
#	undef WINGDIAPI
#	define WINGDIAPI __declspec( dllexport )
#	undef APIENTRY
#	define APIENTRY __stdcall
#	undef CALLBACK
#	define CALLBACK __stdcall
#	undef XMLPARSEAPI
#	define XMLPARSEAPI __declspec( dllexport )
#else // !WIN32
#endif // _WIN32

#define M_PI (3.1415926535897932384626433832795)

//#define DEBUG_OUT

#endif /* __OSSPEC__H__ */ 
