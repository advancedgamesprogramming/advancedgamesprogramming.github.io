
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

/* -*- Mode: C++; -*- */
/* VER: $Id: SimulationOptions.cpp,v 1.12.2.1 2008/12/31 03:53:56 berniw Exp $ */
// copyright (c) 2005 by Christos Dimitrakakis <dimitrak@idiap.ch>
/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "SimulationOptions.h"
#include "car.h"

SimulationOptions::SimulationOptions()
{
    option_list.AddOption (PRM_DAMAGE_TYRES, &tyre_damage, 0.0f);
    option_list.AddOption (PRM_DAMAGE_SUSPENSION, &suspension_damage, false);
    option_list.AddOption (PRM_DAMAGE_ALIGNMENT, &alignment_damage, true);
    option_list.AddOption (PRM_DAMAGE_AERO, &aero_damage, false);
    option_list.AddOption (PRM_MODEL_AEROFLOW, &aeroflow_model, SIMPLE);
    option_list.AddOption (PRM_MODEL_TYRE_TEMPERATURE, &tyre_temperature, false);
    option_list.AddOption (PRM_MODEL_AERO_FACTOR, &aero_factor, 4.0f);
}

void SimulationOptions::SetFromSkill (int skill)
{
    switch (skill) {
    case 0:
    case 1:
        option_list.Set(PRM_DAMAGE_TYRES, 0.0f);
        option_list.Set(PRM_DAMAGE_SUSPENSION, false);
        option_list.Set(PRM_DAMAGE_ALIGNMENT, true);
        option_list.Set(PRM_DAMAGE_AERO, false);
        option_list.Set(PRM_MODEL_TYRE_TEMPERATURE, false);
        break;
    case 2:
        option_list.Set(PRM_DAMAGE_TYRES, 0.0f);
        option_list.Set(PRM_DAMAGE_SUSPENSION, false);
        option_list.Set(PRM_DAMAGE_ALIGNMENT, true);
        option_list.Set(PRM_DAMAGE_AERO, false);
        option_list.Set(PRM_MODEL_TYRE_TEMPERATURE, false);
        break;
    case 3:
        option_list.Set(PRM_DAMAGE_TYRES, 0.0f);
        option_list.Set(PRM_DAMAGE_SUSPENSION, true);
        option_list.Set(PRM_DAMAGE_ALIGNMENT, true);
        option_list.Set(PRM_DAMAGE_AERO, true);
        option_list.Set(PRM_MODEL_TYRE_TEMPERATURE, false);
        option_list.Set(PRM_MODEL_AERO_FACTOR, 1.0f);
        option_list.Set(PRM_MODEL_AEROFLOW, SIMPLE);
        break;
    }
}

/**
   After setting defaults, you can customise by loading values from a file.
   If values are not contained in the file then we just use the previously
   defined values.
*/
void SimulationOptions::LoadFromFile(void* handle) {
    GfParmGetStr(handle, SECT_SIMU_SETTINGS, PRM_DAMAGE_TYRES, "none");
    SetFloatFromGfParm (handle, PRM_DAMAGE_TYRES);
    SetBoolFromGfParm (handle, PRM_DAMAGE_SUSPENSION);
    SetBoolFromGfParm (handle, PRM_DAMAGE_ALIGNMENT);
    SetBoolFromGfParm (handle, PRM_DAMAGE_AERO);
    SetBoolFromGfParm (handle, PRM_MODEL_TYRE_TEMPERATURE);
    SetFloatFromGfParm (handle, PRM_MODEL_AERO_FACTOR);
}

void SimulationOptions::SetFloatFromGfParm(void* handle, const char* name) {
    float v;
    option_list.Get(name, v);
    v = GfParmGetNum (handle, SECT_SIMU_SETTINGS, name, (char*) NULL, v);
    option_list.Set(name, v);
}

void SimulationOptions::SetBoolFromGfParm(void* handle, const char* name) {
    bool v;
    option_list.Get(name, v);
    const char* s = GfParmGetStr (handle, SECT_SIMU_SETTINGS, name, "none");
    v = StrToBool (s, v);
    option_list.Set(name, v);
}

bool SimulationOptions::StrToBool (const char* s, bool dontcare)
{
    if (!strcasecmp(s,"true")) {
        return true;
    }
    if (!strcasecmp(s,"false")) {
        return false;
    }
    return dontcare;
}

