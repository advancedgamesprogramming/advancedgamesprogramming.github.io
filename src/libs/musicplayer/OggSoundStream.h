
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

#ifndef __OggSoundStream_h__
#define __OggSoundStream_h__

/***************************************************************************

    file                 : OggSoundStream.h
    created              : Fri Dec 23 17:35:18 CET 2011
    copyright            : (C) 2011 Bernhard Wymann
    email                : berniw@bluewin.ch
    version              : $Id: OggSoundStream.h,v 1.1.2.3 2014/02/05 09:54:43 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

/* Concrete implementation for ogg sound streams */

#define OV_EXCLUDE_STATIC_CALLBACKS

#include <vorbis/vorbisfile.h>
#include "SoundStream.h"

class OggSoundStream : public SoundStream
{
	public:
		OggSoundStream(char* path);
		virtual ~OggSoundStream();
		
		virtual int getRateInHz() { return rateInHz; }
		virtual SoundFormat getSoundFormat() { return format; }
		
		virtual bool read(char* buffer, const int bufferSize, int* resultSize, const char** error);
		virtual void rewind();
		virtual void display();
		virtual bool isValid() { return valid; }

	protected:
		
	private:
		const char* errorString(int code);
		
		OggVorbis_File	oggStream;
		bool			valid;
		int				rateInHz;
		SoundFormat		format;
};

#endif // __OggSoundStream_h__