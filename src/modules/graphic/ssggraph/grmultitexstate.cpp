
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

    file                 : grmultitexstate.cpp
    created              : Fri Mar 22 23:16:44 CET 2002
    copyright            : (C) 2001 by Christophe Guionneau
    version              : $Id: grmultitexstate.cpp,v 1.4 2004/11/26 15:37:47 olethros Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <plib/ssg.h>
#include "grmultitexstate.h"

#ifdef DMALLOC
#include "dmalloc.h"
#endif
#include "grmain.h"

void grMultiTexState::apply (int unit)
{
  if (unit==0) {
      glActiveTextureARB ( GL_TEXTURE0_ARB ) ;
      glEnable ( GL_TEXTURE_2D ) ;  /* Enables the second texture map. */
      glBindTexture ( GL_TEXTURE_2D, ssgSimpleState::getTextureHandle() ) ;
  } else if (unit==1) {
      glActiveTextureARB ( GL_TEXTURE1_ARB ) ;
      glEnable ( GL_TEXTURE_2D ) ;  /* Enables the second texture map. */
      /* glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);*/
      /*glBlendFunc(GL_ZERO, GL_SRC_COLOR);*/
      glBindTexture ( GL_TEXTURE_2D, ssgSimpleState::getTextureHandle() ) ;
  } else if (unit==2) {
      glActiveTextureARB ( GL_TEXTURE2_ARB ) ;
      glEnable ( GL_TEXTURE_2D ) ;  /* Enables the second texture map. */
      glBindTexture ( GL_TEXTURE_2D, ssgSimpleState::getTextureHandle() ) ;
  } else if (unit==3) {
      glActiveTextureARB ( GL_TEXTURE3_ARB ) ;
      glEnable ( GL_TEXTURE_2D ) ;  /* Enables the second texture map. */
      glBindTexture ( GL_TEXTURE_2D, ssgSimpleState::getTextureHandle() ) ;
  } else {
      /*glActiveTextureARB ( GL_TEXTURE0_ARB ) ;*/
      glBindTexture ( GL_TEXTURE_2D, getTextureHandle() ) ;
      _ssgCurrentContext->getState()->setTexture ( getTexture () ) ;  
  }
}
