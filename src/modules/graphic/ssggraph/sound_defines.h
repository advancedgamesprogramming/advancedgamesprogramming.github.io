
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

#ifndef SOUND_DEFINES_H
#define SOUND_DEFINES_H
#ifndef M_PI
#define EX_PI 3.1415926535
#else
#define EX_PI M_PI
#endif


#define SPEED_OF_SOUND 340.0
#define NB_CRASH_SOUND	6
#define NB_ENGINE_SOUND 6

#define ACTIVE_VOLUME 0x01
#define ACTIVE_PITCH 0x02
#define ACTIVE_LP_FILTER 0x04
#define ACTIVE_HP_FILTER 0x08
#define ACTIVE_BP_FILTER 0x10
#define ACTIVE_DISTORT_FILTER 0x20

#endif