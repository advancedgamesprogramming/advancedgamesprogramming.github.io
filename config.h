
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

/* config.h.      */
/* config.h.in.   */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

#define HAVE_GL 1

#if !(HAVE_GL)
typedef unsigned int GLenum;
typedef unsigned char GLboolean;
typedef unsigned int GLbitfield;
typedef signed char GLbyte;
typedef short GLshort;
typedef int GLint;
typedef int GLsizei;
typedef unsigned char GLubyte;
typedef unsigned short GLushort;
typedef unsigned int GLuint;
typedef float GLfloat;
typedef float GLclampf;
typedef double GLdouble;
typedef double GLclampd;
typedef void GLvoid;

#define GLUT_KEY_LEFT			100
#define GLUT_KEY_UP			101
#define GLUT_KEY_RIGHT			102
#define GLUT_KEY_DOWN			103
#define GLUT_KEY_PAGE_UP		104
#define GLUT_KEY_PAGE_DOWN		105
#define GLUT_KEY_HOME			106
#define GLUT_KEY_END			107
#define GLUT_KEY_INSERT			108

#define GLUT_KEY_F1			1
#define GLUT_KEY_F2			2
#define GLUT_KEY_F3			3
#define GLUT_KEY_F4			4
#define GLUT_KEY_F5			5
#define GLUT_KEY_F6			6
#define GLUT_KEY_F7			7
#define GLUT_KEY_F8			8
#define GLUT_KEY_F9			9
#define GLUT_KEY_F10			10
#define GLUT_KEY_F11			11
#define GLUT_KEY_F12			12

#define GLUT_ACTIVE_SHIFT               1
#define GLUT_ACTIVE_CTRL                2
#define GLUT_ACTIVE_ALT                 4
#define GLUT_DOWN			0
#define GLUT_UP				1
#endif


/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `dl' library (-ldl). */
#define HAVE_LIBDL 1

/* Define to 1 if you have the `GL' library (-lGL). */
#define HAVE_LIBGL 1

/* Define to 1 if you have the `GLU' library (-lGLU). */
#define HAVE_LIBGLU 1

/* Define to 1 if you have the `glut' library (-lglut). */
#define HAVE_LIBGLUT 1

/* Define to 1 if you have the `ICE' library (-lICE). */
#define HAVE_LIBICE 1

/* Define to 1 if you have the `m' library (-lm). */
#define HAVE_LIBM 1

/* Define to 1 if you have the `plibjs' library (-lplibjs). */
#define HAVE_LIBPLIBJS 1

/* Define to 1 if you have the `plibsg' library (-lplibsg). */
#define HAVE_LIBPLIBSG 1

/* Define to 1 if you have the `plibsl' library (-lplibsl). */
#define HAVE_LIBPLIBSL 1

/* Define to 1 if you have the `plibsm' library (-lplibsm). */
#define HAVE_LIBPLIBSM 1

/* Define to 1 if you have the `plibssg' library (-lplibssg). */
#define HAVE_LIBPLIBSSG 1

/* Define to 1 if you have the `plibssgaux' library (-lplibssgaux). */
#define HAVE_LIBPLIBSSGAUX 1

/* Define to 1 if you have the `plibul' library (-lplibul). */
#define HAVE_LIBPLIBUL 1

/* Define to 1 if you have the `png' library (-lpng). */
#define HAVE_LIBPNG 1

/* Define to 1 if you have the `SM' library (-lSM). */
#define HAVE_LIBSM 1

/* Define to 1 if you have the `X11' library (-lX11). */
#define HAVE_LIBX11 1

/* Define to 1 if you have the `Xext' library (-lXext). */
#define HAVE_LIBXEXT 1

/* Define to 1 if you have the `Xi' library (-lXi). */
#define HAVE_LIBXI 1

/* Define to 1 if you have the `Xmu' library (-lXmu). */
#define HAVE_LIBXMU 1

/* Define to 1 if you have the `Xrandr' library (-lXrandr). */
#define HAVE_LIBXRANDR 1

/* Define to 1 if you have the `Xrender' library (-lXrender). */
#define HAVE_LIBXRENDER 1

/* Define to 1 if you have the `Xt' library (-lXt). */
#define HAVE_LIBXT 1

/* Define to 1 if you have the `Xxf86vm' library (-lXxf86vm). */
#define HAVE_LIBXXF86VM 1

/* Define to 1 if you have the `z' library (-lz). */
#define HAVE_LIBZ 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strndup' function. */
#undef HAVE_STRNDUP

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Name of package */
#define PACKAGE "torcs"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME ""

/* Define to the full name and version of this package. */
#define PACKAGE_STRING ""

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME ""

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION ""

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Version number of package */
#define VERSION "0.0.9"

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif
