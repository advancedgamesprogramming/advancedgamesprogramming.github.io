
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

#ifndef _ALUT_H_
#define _ALUT_H_

/* define platform type */
#if !defined(MACINTOSH_AL) && !defined(LINUX_AL) && !defined(WINDOWS_AL)
  #ifdef __APPLE__
    #define MACINTOSH_AL
    #else
    #ifdef _WIN32
      #define WINDOWS_AL
    #else
      #define LINUX_AL
    #endif
  #endif
#endif

#include "al\altypes.h"

#ifdef _WIN32
#define ALUTAPI
#define ALUTAPIENTRY    __cdecl
#define AL_CALLBACK
#else  /* _WIN32 */

#ifdef TARGET_OS_MAC
#if TARGET_OS_MAC
#pragma export on
#endif /* TARGET_OS_MAC */
#endif /* TARGET_OS_MAC */

#ifndef ALUTAPI
#define ALUTAPI
#endif

#ifndef ALUTAPIENTRY
#define ALUTAPIENTRY
#endif

#ifndef AL_CALLBACK
#define AL_CALLBACK
#endif 

#endif /* _WIN32 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ALUT_NO_PROTOTYPES

ALUTAPI ALboolean ALUTAPIENTRY alutInit(ALCchar *szDeviceName, ALCdevice **ppDevice, ALCcontext **ppContext);
ALUTAPI void ALUTAPIENTRY alutExit(ALvoid);

#ifndef MACINTOSH_AL
/* Windows and Linux versions have a loop parameter, Macintosh doesn't */
ALUTAPI void ALUTAPIENTRY alutLoadWAVFile(ALbyte *file, ALenum *format, ALvoid **data, ALsizei *size, ALsizei *freq, ALboolean *loop);
ALUTAPI void ALUTAPIENTRY alutLoadWAVMemory(ALbyte *memory, ALenum *format, ALvoid **data, ALsizei *size, ALsizei *freq, ALboolean *loop);
#else
ALUTAPI void ALUTAPIENTRY alutLoadWAVFile(ALbyte *file, ALenum *format, ALvoid **data, ALsizei *size, ALsizei *freq);
ALUTAPI void ALUTAPIENTRY alutLoadWAVMemory(ALbyte *memory, ALenum *format, ALvoid **data, ALsizei *size, ALsizei *freq);
#endif

ALUTAPI void ALUTAPIENTRY alutUnloadWAV(ALenum format, ALvoid *data, ALsizei size, ALsizei freq);

#else /* ALUT_NO_PROTOTYPES */

    ALboolean (ALUTAPIENTRY *alutInit)( ALCchar *szDeviceName, ALCdevice **ppDevice, ALCcontext **ppContext );
    void 	  (ALUTAPIENTRY *alutExit)( ALvoid );
#ifndef MACINTOSH_AL
    void      (ALUTAPIENTRY *alutLoadWAVFile)( ALbyte *file,ALenum *format,ALvoid **data,ALsizei *size,ALsizei *freq,ALboolean *loop );
    void      (ALUTAPIENTRY *alutLoadWAVMemory)( ALbyte *memory,ALenum *format,ALvoid **data,ALsizei *size,ALsizei *freq,ALboolean *loop );
#else
    void      (ALUTAPIENTRY *alutLoadWAVFile( ALbyte *file,ALenum *format,ALvoid **data,ALsizei *size,ALsizei *freq );
    void      (ALUTAPIENTRY *alutLoadWAVMemory)( ALbyte *memory,ALenum *format,ALvoid **data,ALsizei *size,ALsizei *freq );
#endif
    void      (ALUTAPIENTRY *alutUnloadWAV)( ALenum format,ALvoid *data,ALsizei size,ALsizei freq );

#endif /* ALUT_NO_PROTOTYPES */

#ifdef TARGET_OS_MAC
#if TARGET_OS_MAC
#pragma export off
#endif /* TARGET_OS_MAC */
#endif /* TARGET_OS_MAC */

#ifdef __cplusplus
}
#endif

#endif
