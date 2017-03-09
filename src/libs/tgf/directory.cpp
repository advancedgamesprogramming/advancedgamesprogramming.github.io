
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
                        directory.cpp -- directory management                       
                             -------------------                                         
    created              : Fri Aug 13 21:58:55 CEST 1999
    copyright            : (C) 1999-2014 by Eric Espie, Bernhard Wymann                       
    email                : torcs@free.fr   
    version              : $Id: directory.cpp,v 1.7.2.3 2014/02/04 14:17:26 berniw Exp $                                  
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
    		This is used for directory manipulation.
    @author	<a href=mailto:torcs@free.fr>Eric Espie</a>
    @version	$Id: directory.cpp,v 1.7.2.3 2014/02/04 14:17:26 berniw Exp $
    @ingroup	dir
*/

#include <stdlib.h>
#ifdef WIN32
#include <windows.h>
#endif
#include <tgf.h>
#include "os.h"

void
gfDirInit(void)
{
}


/** Get the list of files of a given directory
    @ingroup	dir
    @param	dir	directory name
    @return	The list of files
 */
tFList * GfDirGetList(const char *dir)
{
	if (GfOs.dirGetList) {
		return GfOs.dirGetList(dir);
	} else {
		return (tFList*)NULL;
	}
}


/** Get the list of files of a given directory
    @ingroup	dir
    @param	dir	directory name
    @return	The list of files
 */
tFList * GfDirGetListFiltered(const char *dir, const char *suffix)
{
	if (GfOs.dirGetListFiltered) {
		return GfOs.dirGetListFiltered(dir, suffix);
	} else {
		return (tFList*)NULL;
	}
}

/** Free a directory list
    @ingroup	dir
    @param	list	List of files
    @param	freeUserData	User function used to free the user data
    @return	none
*/
void GfDirFreeList(tFList *list, tfDirfreeUserData freeUserData, bool freename, bool freedispname)
{
	if (list) {
		// The list contains at least one element, checked above.
		tFList *rl = list;
		do {
			tFList *tmp = rl;
			rl = rl->next;
			if ((freeUserData) && (tmp->userData)) {
				freeUserData(tmp->userData);
			}
			if (freename && tmp->name != NULL) {
				freez(tmp->name);
			}
			if (freedispname && tmp->dispName != NULL) {
				freez(tmp->dispName);
			}
			free(tmp);
		} while (rl != list);
	}
}

