
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

    file                 : musicplayer.cpp
    created              : Fri Dec 23 17:35:18 CET 2011
    copyright            : (C) 2011 Bernhard Wymann
    email                : berniw@bluewin.ch
    version              : $Id: musicplayer.cpp,v 1.1.2.2 2011/12/29 09:23:24 berniw Exp $

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

#include "musicplayer.h"

#if HAVE_GL
	#include <GL/glut.h>
#endif

#include <string.h>
#include <tgf.h>
#include <portability.h>

#include "OggSoundStream.h"
#include "OpenALMusicPlayer.h"


static bool isEnabled()
{
	const int BUFSIZE = 1024;
	char buf[BUFSIZE];
	snprintf(buf, BUFSIZE, "%s%s", GetLocalDir(), MM_SOUND_PARM_CFG);
	bool enabled = false;
	
	void *handle = GfParmReadFile(buf, GFPARM_RMODE_STD | GFPARM_RMODE_CREAT);
	const char* s = GfParmGetStr(handle, MM_SCT_SOUND, MM_ATT_SOUND_ENABLE, MM_VAL_SOUND_DISABLED);
	
	if (strcmp(s, MM_VAL_SOUND_ENABLED) == 0) {
		enabled = true;
	}
	
	GfParmReleaseHandle(handle);
	return enabled;
}


// Path relative to CWD, e.g "data/music/torcs1.ogg"
static SoundStream* getMenuSoundStream(char* oggFilePath)
{
	static OggSoundStream stream(oggFilePath);
	return &stream;
}


static OpenALMusicPlayer* getMusicPlayer()
{
	const int BUFSIZE = 1024;
	char oggFilePath[BUFSIZE];
	strncpy(oggFilePath, "data/music/torcs1.ogg", BUFSIZE);

	static OpenALMusicPlayer player(getMenuSoundStream(oggFilePath));
	return &player;
}


static void playMenuMusic(int /* value */)
{
	const int nextcallinms = 100;
	
	OpenALMusicPlayer* player = getMusicPlayer();
	if (player->playAndManageBuffer()) 
	{
#if HAVE_GL
		glutTimerFunc(nextcallinms, playMenuMusic, 0);
#endif
	}
}


void startMenuMusic()
{
	if (isEnabled()) {
		OpenALMusicPlayer* player = getMusicPlayer();
		player->start();
		playMenuMusic(0);
	}
}


void stopMenuMusic()
{
	OpenALMusicPlayer* player = getMusicPlayer();
	player->stop();
	player->rewind();
}