
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
                        guifont.h -- Interface file for guifont                          
                             -------------------                                         
    created              : Fri Aug 13 22:20:04 CEST 1999
    copyright            : (C) 1999 by Eric Espie                         
    email                : torcs@free.fr   
    version              : $Id: guifont.h,v 1.2 2003/06/24 21:02:25 torcs Exp $                                  
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
 
#ifndef _GUIFONT_H_
#define _GUIFONT_H_

//glFont character structure (DO NOT MODIFY)
typedef struct
{
    float dx, dy;
    float tx1, ty1;
    float tx2, ty2;
} GLFONTCHAR;

//glFont structure (DO NOT MODIFY)
typedef struct
{
    uint Tex;
    int TexWidth, TexHeight;
    int IntStart, IntEnd;
    GLFONTCHAR *Char;
} GLFONT;

class GfuiFontClass
{
protected:
    GLFONT	*font;
    float	size;

public:
  GfuiFontClass(char *font);

  ~GfuiFontClass();

  void create(int point_size);

  void output(int x, int y, const char* text);

  int getWidth(const char* text);
  int getHeight() const;
  int getDescender() const;
};

extern GfuiFontClass	*gfuiFont[];

#endif /* _GUIFONT_H_ */ 



