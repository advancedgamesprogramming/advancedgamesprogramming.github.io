
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

#ifndef _GRSKIDMARKS_H_
#define _GRSKIDMARKS_H_
#define DELTATSTRIP 0.3f
#define MAXPOINT_BY_STRIP 600
#define MAXSTRIP_BYWHEEL  40
#define DIST_INTERVAL     0.2f

#define SKID_UNUSED  1
#define SKID_BEGIN   2
#define SKID_RUNNING 3
#define SKID_STOPPED 4

extern int grSkidMaxStripByWheel;
extern int grSkidMaxPointByStrip;
extern double grSkidDeltaT;

typedef struct 
{
  ssgVertexArray	**vtx; /* the strips */
  ssgVtxTableShadow	**vta;
  ssgTexCoordArray  **tex; 
  ssgColourArray        **clr;
	sgVec4 smooth_colour;
	int			*state;
  int			*size;
  double		timeStrip;
  int			running_skid;
  int			next_skid;
  int			last_state_of_skid;
  int			skid_full;
  float         tex_state;
}tgrSkidStrip;

typedef struct 
{
  ssgVtxTable	*base; /* to remember the pos of the wheel line before transform */
  tgrSkidStrip	strips[4]; /* the strips of the four wheels*/
}tgrSkidmarks;

extern void grInitSkidmarks(tCarElt *car);
extern void grUpdateSkidmarks(tCarElt *car, double t);
extern void grShutdownSkidmarks (void);
extern void grDrawSkidmarks (tCarElt *car);

#endif /* _GRSKIDMARKS_*/
