
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
                                   TRACE                   
                             -------------------                                         
    created              : Fri Aug 13 22:32:45 CEST 1999
    copyright            : (C) 1999 by Eric Espie                         
    email                : torcs@free.fr   
    version              : $Id: trace.cpp,v 1.7.2.2 2011/12/28 15:02:36 berniw Exp $                                  
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
    Allow the trace in the file <tt>trace.txt</tt>
    @author	<a href=mailto:torcs@free.fr>Eric Espie</a>
    @version	$Id: trace.cpp,v 1.7.2.2 2011/12/28 15:02:36 berniw Exp $
    @ingroup	trace
*/


#ifdef _WIN32
#include <windows.h>
#include <windowsx.h>
#endif /* _WIN32 */

#include <stdio.h>
#include <assert.h>
#include <time.h>
#ifdef WIN32
#include <windows.h>
#endif
#include <tgf.h>

/* static FILE *outTrace = (FILE*)NULL; */

/* static char TraceStr[1024]; */

void
gfTraceInit(void)
{
}

/* void GfFatal(char *fmt, ...) */
/* { */
/*     va_list ap; */
/*     va_start(ap, fmt); */
/*     GfTrace(fmt, ap); */
/*     va_end(ap); */
/*     exit(1); */
/* } */


/** Print a message in the trace file.
    The file is openned the first time
    @ingroup	trace
    @param	szTrc	message to trace
*/
/* void GfTrace(char *fmt, ...) */
/* { */
/*     va_list		ap; */
/*     struct tm		*stm; */
/*     time_t		t; */
/*     char		*s = TraceStr; */

/*     fprintf(stderr, "ERROR: "); */
/*     va_start(ap, fmt); */
/*     vfprintf(stderr, fmt, ap); */
/*     va_end(ap); */
/*     fflush(stderr); */

/*     if (outTrace == NULL) { */
/* 	if ((outTrace = fopen("trace.txt", "w+")) == NULL) { */
/* 	    perror("trace.txt"); */
/* 	    return; */
/* 	} */
/*     } */
/*     t = time(NULL); */
/*     stm = localtime(&t); */
/*     s += snprintf(TraceStr, "%4d/%02d/%02d %02d:%02d:%02d ", */
/* 		 stm->tm_year+1900, stm->tm_mon+1, stm->tm_mday, */
/* 		 stm->tm_hour, stm->tm_min, stm->tm_sec); */

/*     va_start(ap, fmt); */
/*     vsnprintf(s, 1023 - strlen(TraceStr), fmt, ap); */
/*     va_end(ap); */

/*     fwrite(TraceStr, strlen(TraceStr), 1, outTrace); */
/*     fflush(outTrace); */
/* } */

