
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

    file                 : splash.cpp
    created              : Sat Mar 18 23:49:03 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: splash.cpp,v 1.4.2.6 2012/06/10 01:59:35 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <config.h>

#ifdef WIN32
#include <windows.h>
#define HAVE_CONFIG_H
#endif

#if HAVE_GL
	#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <portability.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <tgfclient.h>

#include "splash.h"
#include "mainmenu.h"

static int s_imgWidth, s_imgHeight;
static GLuint s_texture = 0;
static int SplashDisplaying;

/*
 * Function
 *	splashKey
 *
 * Description
 *	
 *
 * Parameters
 *	
 *
 * Return
 *	
 *
 * Remarks
 *	
 */
static void splashKey( unsigned char /* key */, int /* x */, int /* y */)
{
	SplashDisplaying = 0;
#if HAVE_GL
	glDeleteTextures(1, &s_texture);
#endif
	s_texture = 0;
	TorcsMainMenuRun();
}

/*
 * Function
 *	
 *
 * Description
 *	
 *
 * Parameters
 *	
 *
 * Return
 *	
 *
 * Remarks
 *	
 */
static void splashTimer(int /* value */)
{
	if (SplashDisplaying) {
		SplashDisplaying = 0;
#if HAVE_GL
		glDeleteTextures(1, &s_texture);
#endif
		s_texture = 0;
		TorcsMainMenuRun();
	}
}
	

/*
 * Function
 *	splashDisplay
 *
 * Description
 *
 *
 * Parameters
 *	
 *
 * Return
 *	
 *
 * Remarks
 *	
 */
static void splashDisplay( void )
{
	int	ScrW, ScrH, ViewW, ViewH;
	
	SplashDisplaying = 1;
		
#if HAVE_GL
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glDisable(GL_CULL_FACE);
	glDisable(GL_ALPHA_TEST);
#endif
	GfScrGetSize(&ScrW, &ScrH, &ViewW, &ViewH);
	
#if HAVE_GL
	glViewport((ScrW-ViewW) / 2, (ScrH-ViewH) / 2, ViewW, ViewH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, ScrW, 0, ScrH);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
#endif
	if (s_texture != 0) {
		GLfloat tx1 = 0.0f, tx2 = 1.0f, ty1 = 0.0f, ty2 = 1.0f;
		
		// Compute texture coordinates to ensure proper unskewed/unstretched display of
		// image content.
		//tdble rfactor = (float)(s_imgWidth*ViewH)/(float)(s_imgHeight*ViewW);
		tdble rfactor = (16.0f*ViewH)/(10.0f*ViewW);

		if (rfactor >= 1.0f) {
			// Aspect ratio of view is smaller than 16:10, "cut off" sides
			tdble tdx = (1.0f-1.0f/rfactor)/2.0f;
			tx1 += tdx;
			tx2 -= tdx;
		} else {
			// Aspect ratio of view is larger than 16:10, "cut off" top and bottom
			tdble tdy = (1.0f-rfactor)/2.0f;
			ty1 += tdy;
			ty2 -= tdy;
		}

#if HAVE_GL
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, s_texture);
		glBegin(GL_QUADS);
		glTexCoord2f(tx1, ty1); glVertex3f(0.0, 0.0, 0.0);
		glTexCoord2f(tx1, ty2); glVertex3f(0.0, ScrH, 0.0);
		glTexCoord2f(tx2, ty2); glVertex3f(ScrW, ScrH, 0.0);
		glTexCoord2f(tx2, ty1); glVertex3f(ScrW, 0.0, 0.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
#endif
	}
		
#ifdef HAVE_CONFIG_H
#if HAVE_GL
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
#endif
	static float grWhite[4] = {1.0, 1.0, 1.0, 1.0};
	GfuiPrintString(VERSION, grWhite, GFUI_FONT_SMALL_C, 640-8, 8, GFUI_ALIGN_HR_VB);
#endif

#if HAVE_GL
	glutSwapBuffers();
#endif
}

static void splashMouse(int /* b */, int s, int /* x */, int /* y */)
{
	if (s == GLUT_UP) 
	{
		SplashDisplaying = 0;
#if HAVE_GL
		glDeleteTextures(1, &s_texture);
#endif
		s_texture = 0;
		TorcsMainMenuRun();
	}
}


/*
 * Function
 *	
 *
 * Description
 *	
 *
 * Parameters
 *	
 *
 * Return
 *	
 *
 * Remarks
 *	
 */
int SplashScreen(void)
{
	void	*handle;
	float	screen_gamma;
	const char	*filename = "data/img/splash.png";
	const int BUFSIZE = 1024;
	char buf[BUFSIZE];
	
	if (s_texture != 0) 
	{
#if HAVE_GL
		glDeleteTextures(1, &s_texture); 
#endif
	}
	
	snprintf(buf, BUFSIZE, "%s%s", GetLocalDir(), GFSCR_CONF_FILE);
	handle = GfParmReadFile(buf, GFPARM_RMODE_STD | GFPARM_RMODE_CREAT);
	screen_gamma = (float)GfParmGetNum(handle, GFSCR_SECT_PROP, GFSCR_ATT_GAMMA, (char*)NULL, 2.0);	
	GLbyte *tex = (GLbyte*)GfImgReadPng(filename, &s_imgWidth, &s_imgHeight, screen_gamma);
	GfParmReleaseHandle(handle);
	if (!tex) {
		GfTrace("Couldn't read %s\n", filename);
		return -1;
	}

#if HAVE_GL
	glGenTextures(1, &s_texture);
	glBindTexture(GL_TEXTURE_2D, s_texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, s_imgWidth, s_imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid *)(tex));
	free(tex);
	
	glutDisplayFunc(splashDisplay);
	glutKeyboardFunc(splashKey);
	glutSpecialFunc((void (*)(int key, int x, int y))NULL);
	glutTimerFunc(7000, splashTimer, 0);
	glutMouseFunc(splashMouse);
#endif
	return 0;
}


