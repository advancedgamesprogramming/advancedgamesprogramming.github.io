
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

    file                 : glfeatures.h
    created              : Wed Jun 1 14:56:31 CET 2005
    copyright            : (C) 2005 by Bernhard Wymann
    version              : $Id: glfeatures.h,v 1.2 2005/08/05 09:26:39 berniw Exp $

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
	Functions to check if features seems to be available and requested by the
	user. The isAvailable functions should return if a feature is working on
	the system, the isEnabled feature should check if the user wants to enable
	it as well.
	It should NOT check if the features are really working, that is subject
	to another part eventually.
*/

#ifndef _GRFEATURES_H_
#define _GRFEATURES_H_

#include <config.h>

#ifdef WIN32
#include <windows.h>
#if HAVE_GL
#include <GL/gl.h>
#include <GL/glext.h>
#endif
#else
#if HAVE_GL
#include <GL/gl.h>
#endif
#endif // WIN32

#include <tgfclient.h>
#include <graphic.h>

// Initialize
extern void checkGLFeatures(void);

// GL_ARB_texture_compression
extern bool isCompressARBAvailable(void);
extern bool isCompressARBEnabled(void);
extern void updateCompressARBEnabled(void);

extern int getUserTextureMaxSize(void);
extern int getGLTextureMaxSize(void);
extern void updateUserTextureMaxSize(void);

#endif // _GRFEATURES_H_

