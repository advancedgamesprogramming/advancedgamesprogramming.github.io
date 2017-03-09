
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

// -*- Mode: c++ -*-
/***************************************************************************

    file                 : geometry.h
    created              : Mon Nov 22 0:10:00 CET 2004
    copyright            : (C) 2004 by Christos Dimitrakakis
    email                : dimitrak@idiap.ch
    version              : $Id: geometry.h,v 1.6 2005/04/10 23:37:01 olethros Exp $

 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <vector>

class Vector
{
 public:
	enum BoundsCheckingStatus {NO_CHECK_BOUNDS=0, CHECK_BOUNDS=1};
	float* x;
	int n;
	Vector (int N_, enum BoundsCheckingStatus check = NO_CHECK_BOUNDS);
	Vector (const Vector& rhs);
	~Vector ();
	Vector& operator= (const Vector& rhs);
	void Resize(int N_);
	float& operator[] (int index); ///< return element for read-write
	const float& operator[] (int index) const; ///< return element for read
	int Size() { return n;}
private:
	int maxN;
	enum BoundsCheckingStatus checking_bounds;

};

float DotProd(Vector* A, Vector* B);
void Sub (Vector* A, Vector* B, Vector* R);

/// Represent a line as an origin vector and a direction vector.
class ParametricLine
{
 public:
	Vector* Q; // direction
	Vector* R; // origin
	ParametricLine (Vector* A, Vector* B);
	~ParametricLine();
	void PointCoords (float t, Vector* X);
};

class ParametricSphere
{
 public:
	Vector* C; //center
	float r; // radius
	ParametricSphere(Vector* C, float r);
	ParametricSphere(int N);
	~ParametricSphere();
};


Vector* GetNormalToLine(Vector* R);
float IntersectLineLine(ParametricLine* A, ParametricLine* B);
float CalculateRadiusPoints (std::vector<Vector> P);
Vector* IntersectSphereLine(ParametricLine* line, Vector* C, float r);

void EstimateSphere (std::vector<Vector> P, ParametricSphere* sphere);
#endif
