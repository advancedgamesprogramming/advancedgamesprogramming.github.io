
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

    file                 : OpenAlMusicPlayer.cpp
    created              : Fri Dec 23 17:35:18 CET 2011
    copyright            : (C) 2011 Bernhard Wymann
    email                : berniw@bluewin.ch
    version              : $Id: OpenALMusicPlayer.cpp,v 1.1.2.3 2014/02/05 09:54:43 berniw Exp $

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

#include <stdio.h>
#include <tgf.h>
#include "OpenALMusicPlayer.h"

const int OpenALMusicPlayer::BUFFERSIZE = 4096*64;

OpenALMusicPlayer::OpenALMusicPlayer(SoundStream* soundStream):
	device(NULL),
	context(NULL),
	source(0),
	stream(soundStream),
	ready(false)
{
	buffers[0] = 0;
	buffers[1] = 0;
}




OpenALMusicPlayer::~OpenALMusicPlayer()
{
	if (ready) {
		stop();
	}
}




void OpenALMusicPlayer::stop()
{
	if (!ready) {
		return;
	}
	
#if HAVE_AL
	alSourceStop(source);
    
	int queued;
	
	alGetSourcei(source, AL_BUFFERS_QUEUED, &queued);
	while (queued--) {
		ALuint buffer;
		alSourceUnqueueBuffers(source, 1, &buffer);
		check();
	}
	
    alDeleteSources(1, &source);
    check();
    alDeleteBuffers(2, buffers);
    check();
	
	alcMakeContextCurrent(NULL);
	alcDestroyContext(context);
	alcCloseDevice(device);
#endif
	ready = false;
}




bool OpenALMusicPlayer::initContext()
{
#if HAVE_AL
	device = alcOpenDevice(NULL);
	if( device == NULL ) {
		GfError("OpenALMusicPlayer: OpenAL could not open device\n");
		return false;
	}

	context = alcCreateContext(device, NULL);
	if(context == NULL) {
		alcCloseDevice(device);
		GfError("OpenALMusicPlayer: OpenAL could not create contect for device\n");
		return false;
	}

	alcMakeContextCurrent(context);
	alcGetError(device);
#endif	
	return check();

}




bool OpenALMusicPlayer::initBuffers()
{
#if HAVE_AL
	alGenBuffers(2, buffers);
#endif
	return check();
}




bool OpenALMusicPlayer::initSource()
{
#if HAVE_AL
    alGenSources(1, &source);
    if (!check()) {
		GfError("OpenALMusicPlayer: initSource failed to get sound source.\n");
		return false;
	};
    
    alSource3f(source, AL_POSITION,        0.0, 0.0, 0.0);
    alSource3f(source, AL_VELOCITY,        0.0, 0.0, 0.0);
    alSource3f(source, AL_DIRECTION,       0.0, 0.0, 0.0);
    alSourcef (source, AL_ROLLOFF_FACTOR,  0.0          );
    alSourcei (source, AL_SOURCE_RELATIVE, AL_TRUE      );
#endif
	return true;
}




bool OpenALMusicPlayer::check()
{
#if HAVE_AL
	int error = alGetError();

	if(error != AL_NO_ERROR) {
		GfError("OpenALMusicPlayer: OpenAL error was raised: %d\n", error);
		return false;
	}
#endif
	return true;
}




bool OpenALMusicPlayer::isPlaying()
{
#if HAVE_AL
    ALenum state;
	
    alGetSourcei(source, AL_SOURCE_STATE, &state);    
    return (state == AL_PLAYING);
#else
	return false;
#endif
}



bool OpenALMusicPlayer::streamBuffer(ALuint buffer)
{
#if HAVE_AL
	char pcm[BUFFERSIZE];
	int size = 0;
	const char* error = '\0';
	
	if (!stream->read(pcm, BUFFERSIZE, &size, &error)) {
		GfError("OpenALMusicPlayer: Stream read error: %s\n", error);
		return false;
	} else {
		int format;
		switch (stream->getSoundFormat()) {
			case SoundStream::FORMAT_MONO16:
				format = AL_FORMAT_MONO16;
				break;
			case SoundStream::FORMAT_STEREO16:
				format = AL_FORMAT_STEREO16;
				break;
			default:
				GfError("OpenALMusicPlayer: Format error: \n");
				return false;
		}
		
		alBufferData(buffer, format, pcm, size, stream->getRateInHz());
		return check();
	}
#else
	return false;
#endif
}




void OpenALMusicPlayer::start()
{
#if HAVE_AL
	if (!ready) 
	{
		if (stream->getSoundFormat() == SoundStream::FORMAT_INVALID) {
			GfError("OpenALMusicPlayer: Sound stream has invalid format\n");
			return;
		}
		
		if (initContext() && initBuffers() && initSource()) {
			ready = true;
			startPlayback();
		}
		
		return;
	}
#endif
}




void OpenALMusicPlayer::rewind()
{
#if HAVE_AL
	stream->rewind();
#endif
}




bool OpenALMusicPlayer::playAndManageBuffer()
{
#if HAVE_AL
	if (!ready) {
		return false;
	}
	
	int processed;
	bool active = true;

	alGetSourcei(source, AL_BUFFERS_PROCESSED, &processed);

	while(processed--) {
		ALuint buffer;
		
		alSourceUnqueueBuffers(source, 1, &buffer);
		check();
		active = streamBuffer(buffer);
		alSourceQueueBuffers(source, 1, &buffer);
		check();
	}

	if (!active && !isPlaying()) {
		// Try to reanimate playback
		if(!startPlayback()) {
			GfError("OpenALMusicPlayer: Cannot play stream.\n");
		}
	}
#endif
	return true;
}




bool OpenALMusicPlayer::startPlayback()
{
#if HAVE_AL
    if(isPlaying()) {
        return true;
	}
	
    if(!streamBuffer(buffers[0])) {
        return false;
	}
        
    if(!streamBuffer(buffers[1])) {
        return false;
	}
    
    alSourceQueueBuffers(source, 2, buffers);
    alSourcePlay(source);
#endif
    return true;
}