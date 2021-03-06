
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

    file                 : rttelem.cpp
    created              : Mon Feb 28 22:38:31 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: rttelem.cpp,v 1.8.2.2 2011/12/28 15:00:48 berniw Exp $

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
    		This is a collection of useful functions for using telemetry in a robot.
		You can see an example of telemetry usage in the human driver.
    @author	<a href=mailto:torcs@free.fr>Eric Espie</a>
    @version	$Id: rttelem.cpp,v 1.8.2.2 2011/12/28 15:00:48 berniw Exp $
    @ingroup	robottools
*/

/** @defgroup telemetry		Telemetry tools for robots.
    The telemetry is only working with Linux.
    <br>The graphs are build by gnuplot.
    @ingroup	robottools
*/
    
#include <stdlib.h>
#include <stdio.h>
#ifdef WIN32
#include <windows.h>
#endif
#include <telemetry.h>
#include <robottools.h>
#include <tgf.h>
#include <portability.h>



FILE _iob[] = { *stdin, *stdout, *stderr };

extern "C" FILE * __cdecl __iob_func(void)
{
	return _iob;
}



#if 0
static tTelemItf	tlm;
static tModList		*modlist = (tModList*)NULL;
#endif

/** Initialization of a telemetry session.
    @ingroup	telemetry
    @param	ymin	Minimum value for Y.
    @param	ymax	Maximum value for Y.
    @return	None
 */
void RtTelemInit(tdble ymin, tdble ymax)
{
#ifdef later
	const int BUFSIZE = 256;
    char	buf[BUFSIZE];
    tModInfo	*curModInfo;

    memset(&tlm, 0, sizeof(tTelemItf));
    snprintf(buf, BUFSIZE, "%smodules/telemetry/%s.%s", "telemetry", GetLibDir (), DLLEXT);
    if (GfModLoad(TLM_IDENT, buf, &modlist)) return;
    GfOut("--- %s loaded ---\n", modlist->modInfo->name);
    curModInfo = modlist->modInfo;
    curModInfo->fctInit(curModInfo->index, &tlm);

    tlm.init(ymin, ymax);
#endif
}


/** Create a new telemetry channel.
    @ingroup	telemetry
    @param	name	Name of the channel.
    @param	var	Address of the variable to monitor.
    @param	min	Minimum value of this variable.
    @param	max	Maximum value of this variable.
    @return	None
 */
void RtTelemNewChannel(const char * name, tdble * var, tdble min, tdble max)
{
#if 0
    tlm.newChannel(name, var, min, max);
#endif
}

/** Start recording into a file.
    @ingroup	telemetry
    @param	filename	name of the file to use.
    @return	none.
 */
void RtTelemStartMonitoring(const char * filename)
{
#if 0
    tlm.startMonitoring(filename);
#endif
}

/** Stop recording and close the file.
    @ingroup	telemetry
    @return	none
 */
void RtTelemStopMonitoring(void)
{
#if 0
    tlm.stopMonitoring();
#endif
}

/** Record a new set of values.
    @ingroup	telemetry
    @param	time	current time.
    @return	None.
 */
void RtTelemUpdate(double time)
{
#if 0
    tlm.update(time);
#endif
}

/** Deinstall the telemetry module.
    @ingroup	telemetry
    @return	none.
 */
void RtTelemShutdown(void)
{
#if 0
    tlm.shutdown();
    GfModUnloadList(&modlist);
#endif
}

