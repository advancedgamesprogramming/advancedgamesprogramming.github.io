
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

#ifndef __OpenALMusicPlayer_h__
#define __OpenALMusicPlayer_h__

/***************************************************************************

    file                 : OpenAlMusicPlayer.h
    created              : Fri Dec 23 17:35:18 CET 2011
    copyright            : (C) 2011 Bernhard Wymann
    email                : berniw@bluewin.ch
    version              : $Id: OpenALMusicPlayer.h,v 1.1.2.1 2011/12/28 15:11:57 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <AL/al.h>
#include <AL/alc.h>
#include "SoundStream.h"

class OpenALMusicPlayer
{
	public:
		OpenALMusicPlayer(SoundStream* soundStream);
		virtual ~OpenALMusicPlayer();
		
		virtual void start();
		virtual void stop();
		virtual void rewind();
		virtual bool playAndManageBuffer();

	protected:
		virtual bool initContext();
		virtual bool initBuffers();
		virtual bool initSource();
		virtual bool check();
		virtual bool startPlayback();
		virtual bool isPlaying();
		virtual bool streamBuffer(ALuint buffer);
		
		ALCdevice* device;
		ALCcontext* context;
		ALuint source;								// audio source 
		ALuint buffers[2];							// front and back buffers
		
		SoundStream* stream;
		bool ready;									// initialization sucessful
		static const int BUFFERSIZE;
};
#endif // __OpenALMusicPlayer_h__