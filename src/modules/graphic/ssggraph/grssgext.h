
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

    file                 : grssgext.h
    created              : Wed Aug 30 01:35:45 CEST 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: grssgext.h,v 1.7 2005/06/03 23:51:20 berniw Exp $

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
    		This file contains the divergences from PLIB.
		I derived PLIB objects to adapt them to my needs.
    @author	<a href=mailto:torcs@free.fr>Eric Espie</a>
    @version	$Id: grssgext.h,v 1.7 2005/06/03 23:51:20 berniw Exp $
*/

#ifndef _GRSSGEXT_H_
#define _GRSSGEXT_H_

#include "grtexture.h"

/*
 * An ssgBranch with pre and post draw callbacks.
 * It must be clear that all the children nodes
 * have to be non-transparent in order to be 
 * drawn immediately.
 */
class ssgBranchCb : public ssgBranch
{

 protected:

  ssgCallback  preDrawCB;
  ssgCallback postDrawCB;

 public:

  ssgBranchCb(void):ssgBranch() {
    preDrawCB = NULL;
    postDrawCB = NULL;
  }

  void cull  ( sgFrustum *f, sgMat4 m, int test_needed )
    {
      int cull_result = cull_test ( f, m, test_needed ) ;

      if ( cull_result == SSG_OUTSIDE )
	return ;

      if ( preDrawCB != NULL && ! (*preDrawCB)(this) )
	return ;

      for ( ssgEntity *e = getKid ( 0 ) ; e != NULL ; e = getNextKid() )
	e -> cull ( f, m, cull_result != SSG_INSIDE ) ;

      if ( postDrawCB != NULL )
	(*postDrawCB)(this) ;
    }

  void setCallback ( int cb_type, ssgCallback cb ) {
    if ( cb_type == SSG_CALLBACK_PREDRAW )
      preDrawCB = cb ;
    else
      postDrawCB = cb ;
  }

};


/* Use the texture name to select options like mipmap */
class ssgLoaderOptionsEx : public ssgLoaderOptions {
	public:
		ssgLoaderOptionsEx():ssgLoaderOptions() {}

		ssgTexture* createTexture(char* tfname, int wrapu = TRUE, int wrapv = TRUE, int mipmap = TRUE) 
		{
			mipmap = doMipMap(tfname, mipmap);
			return ssgLoaderOptions::createTexture(tfname, wrapu, wrapv, mipmap) ;
		}

		virtual void makeModelPath ( char* path, const char *fname ) const
		{
			ulFindFile ( path, model_dir, fname, NULL ) ;
		}

		virtual void makeTexturePath ( char* path, const char *fname ) const
		{
			ulFindFile ( path, texture_dir, fname, NULL ) ;
		}
};



#endif /* _GRSSGEXT_H_ */ 



