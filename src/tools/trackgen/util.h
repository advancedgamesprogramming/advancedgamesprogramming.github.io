
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

    file                 : util.h
    created              : Wed May 29 22:20:44 CEST 2002
    copyright            : (C) 2001 by Eric Espi�
    email                : Eric.Espie@torcs.org
    version              : $Id: util.h,v 1.3.2.2 2012/02/09 21:43:38 berniw Exp $

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
    @version	$Id: util.h,v 1.3.2.2 2012/02/09 21:43:38 berniw Exp $
*/

#ifndef _UTIL_H_
#define _UTIL_H_

#include <plib/ssg.h>

extern int GetFilename(const char *filename, const char *filepath, char *buf, const int BUFSIZE);
extern float getHOT(ssgRoot *root, float x, float y);

/* Use the texture name to select options like mipmap */
class ssgLoaderOptionsEx : public ssgLoaderOptions
{
 public:
    ssgLoaderOptionsEx()
	: ssgLoaderOptions() 
	{}

    virtual void makeModelPath ( char* path, const char *fname ) const
	{
	    ulFindFile ( path, model_dir, fname, NULL ) ;
	}
    
    virtual void makeTexturePath ( char* path, const char *fname ) const
	{
	    ulFindFile ( path, texture_dir, fname, NULL ) ;
	}

};

#endif /* _UTIL_H_ */ 



