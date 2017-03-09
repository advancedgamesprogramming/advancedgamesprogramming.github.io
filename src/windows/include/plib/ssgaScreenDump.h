
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


/* Dump to disk in '.rgb' format */

void ssgaScreenDump ( char *filename,
                      int width, int height,
                      int frontBuffer = TRUE ) ;

/* Put low order 24 bits to disk (R=lsb, G=middle byte, B=msb) */

void ssgaScreenDepthDump ( char *filename,
                      int width, int height,
                      int frontBuffer = TRUE ) ;

/* Dump to a memory buffer - three bytes per pixel */

unsigned char *ssgaScreenDump ( int width, int height,
                                int frontBuffer = TRUE ) ;

unsigned int *ssgaScreenDepthDump ( int width, int height,
                                    int frontBuffer = TRUE ) ;

