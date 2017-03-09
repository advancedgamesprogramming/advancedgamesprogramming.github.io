
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

    file                 : telemetryitf.cpp
    created              : Mon Feb 28 21:18:49 CET 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: telemetryitf.cpp,v 1.3.6.1 2008/12/31 03:53:56 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <stdlib.h>
#include <tgf.h>
#include <telemetry.h>

#include "tlm.h"

#ifdef _WIN32
BOOL WINAPI DllEntryPoint (HINSTANCE hDLL, DWORD dwReason, LPVOID Reserved)
{
    return TRUE;
}
#endif

/*
 * Function
 *	telemInit
 *
 * Description
 *	
 *
 * Parameters
 *	
 *
 * Return
 *	
 */
static int
telemInit(int index, void *pt)
{
    tTelemItf	*ptf = (tTelemItf*)pt;
    
    ptf->init			= TlmInit;
    ptf->newChannel		= TlmNewChannel;
    ptf->startMonitoring	= TlmStartMonitoring;
    ptf->stopMonitoring		= TlmStopMonitoring;
    ptf->update			= TlmUpdate;    
    ptf->shutdown		= TlmShutdown;

    return 0;
}


/*
 * Function
 *	telemetry
 *
 * Description
 *	module entry point
 *
 * Parameters
 *	modinfo : administrative info to be filled by the module
 *
 * Return
 *	0  Ok
 *	-1 NOk
 *
 * Remarks
 *	all the logical modules should be linked in a ring
 */
extern "C" int
telemetry(tModInfo *modInfo)
{
    modInfo->name = strdup("telemetry");	/* name of the module (short) */
    modInfo->desc = strdup("Telemetry module, used to store telemetry information");	/* description of the module (can be long) */
    modInfo->fctInit = telemInit;	/* init function */
    modInfo->gfId = TLM_IDENT;		/* always loaded  */
    modInfo->index = 0;

    return 0;
}



