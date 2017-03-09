
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

    file                 : grutil.h
    created              : Wed Nov  1 22:35:08 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: grutil.h,v 1.11.2.3 2012/06/06 13:56:39 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
 

#ifndef _GRUTIL_H_
#define _GRUTIL_H_

#include <stdio.h>
#include "grtexture.h"

#if 1
#define TRACE_GL(msg) { GLenum rc; if ((rc = glGetError()) != GL_NO_ERROR) printf("%s %s\n", msg, gluErrorString(rc)); }
#else
#define TRACE_GL(msg)
#endif

#ifdef DEBUG
#define DBG_SET_NAME(base, name, index, subindex)		\
{								\
    char __buf__[256];						\
    if (subindex != -1) {					\
        sprintf(__buf__, "%s-%d-%d", name, index, subindex);	\
    } else {							\
	sprintf(__buf__, "%s-%d", name, index);			\
    }								\
    (base)->setName((const char *)__buf__);			\
}
#else
#define DBG_SET_NAME(base, name, index, subindex)
#endif
 

/* Vars to set before calling grSsgLoadTexCb */
extern float	grGammaValue;
extern int	grMipMap;

extern char *grFilePath;	/* Multiple path (: separated) used to search for files */
extern char *grTexturePath;

extern int grGetFilename(const char *filename, char *filepath, char *buf, const int BUFSIZE);
ssgState * grSsgEnvTexState(const char *img);
extern ssgState *grSsgLoadTexState(const char *img);
extern ssgState *grSsgLoadTexStateEx(const char *img, char *filepath, int wrap, int mipmap);
extern bool grLoadPngTexture (const char *fname, ssgTextureInfo* info);
extern void grShutdownState(void);
extern void grWriteTime(float *color, int font, int x, int y, tdble sec, int sgn);
extern float grGetHOT(float x, float y);

void grRemoveState(char* img);

#endif /* _GRUTIL_H_ */ 



