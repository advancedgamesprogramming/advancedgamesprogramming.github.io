
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

#ifndef __SoundStream_h__
#define __SoundStream_h__

/***************************************************************************

    file                 : SoundStream.h
    created              : Fri Dec 23 17:35:18 CET 2011
    copyright            : (C) 2011 Bernhard Wymann
    email                : berniw@bluewin.ch
    version              : $Id: SoundStream.h,v 1.1.2.2 2014/02/05 09:54:43 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

/* Intherface for sound streams */

class SoundStream
{
	public: 
		SoundStream(const char* path) {};
		virtual ~SoundStream() {};
		
		enum SoundFormat {
			FORMAT_INVALID,
			FORMAT_MONO16,
			FORMAT_STEREO16
		};

		virtual int getRateInHz() = 0;
		virtual SoundFormat getSoundFormat() = 0;

		virtual bool read(char* buffer, const int bufferSize, int* resultSize, const char** error) = 0;
		virtual void rewind() = 0;
		virtual void display() = 0;
		// isValid is not nice, but I do not want to introduce exceptions into TORCS at this time
		virtual bool isValid() = 0;
		
};

#endif // __SoundStream_h__