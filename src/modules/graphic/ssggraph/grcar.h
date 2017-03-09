
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

    file                 : grcar.h
    created              : Mon Aug 21 18:21:15 CEST 2000
    copyright            : (C) 2000 by Eric Espie
    email                : torcs@free.fr
    version              : $Id: grcar.h,v 1.19.2.1 2012/06/06 13:56:39 berniw Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

 
#ifndef _GRCAR_H_
#define _GRCAR_H_

typedef struct
{
    ssgSimpleState	*texture;
    GLuint		CounterList;
    GLuint		needleList;
    tdble		needleXCenter, needleYCenter;
    tdble		digitXCenter, digitYCenter;
    tdble		minValue, maxValue;
    tdble		minAngle, maxAngle;
    tdble		*monitored;
    tdble		prevVal;
    tdble		rawPrev;
    int			digital;
} tgrCarInstrument;


typedef struct 
{
    float		iconColor[4];
    ssgTransform	*carTransform;
    ssgSelector		*LODSelector;
	ssgEntity       *carEntity;
    int			LODSelectMask[32];
    float		LODThreshold[32];
    ssgSelector		*driverSelector;
	bool driverSelectorinsg;
    ssgStateSelector	*envSelector;
    ssgTransform	*wheelPos[4];
    ssgTransform	*wheelRot[4];
    ssgColourArray	*brkColor[4];
    ssgSelector		*wheelselector[4];
    ssgState		*wheelTexture;
    ssgVtxTableShadow	*shadowBase;
    ssgVtxTableShadow	*shadowCurr;
    ssgBranch		*shadowAnchor;
    tgrSkidmarks        *skidmarks;
    sgMat4		carPos;
    tgrCarInstrument	instrument[2];
    tdble               distFromStart;
    tdble               envAngle;
    int			fireCount;
    tdble               px;
    tdble               py;
    tdble               sx;
    tdble               sy;
} tgrCarInfo;

extern tgrCarInfo	*grCarInfo;

class myLoaderOptions : public ssgLoaderOptions
{
public:
	virtual void makeModelPath ( char* path, const char *fname ) const
	{
		ulFindFile ( path, model_dir, fname, NULL ) ;
	}

	virtual void makeTexturePath ( char* path, const char *fname ) const
	{
		ulFindFile ( path, texture_dir, fname, NULL ) ;
	}
} ;

extern void grInitCar(tCarElt *car);
extern void grDrawCar(tCarElt*, tCarElt *, int, int, double curTime, class cGrPerspCamera *curCam);
extern void grDrawShadow(tCarElt *car);
extern void grInitShadow(tCarElt *car);
extern tdble grGetDistToStart(tCarElt *car);
extern void grInitCommonState(void);
extern void grPropagateDamage (ssgEntity* l, sgVec3 poc, sgVec3 force, int cnt);
#endif /* _GRCAR_H_ */ 



