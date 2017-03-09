
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

/*
  SOLID - Software Library for Interference Detection
  Copyright (C) 1997-1998  Gino van den Bergen

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Library General Public
  License as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Library General Public License for more details.

  You should have received a copy of the GNU Library General Public
  License along with this library; if not, write to the Free
  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

  Please send remarks, questions and bug reports to gino@win.tue.nl,
  or write to:
                  Gino van den Bergen
		  Department of Mathematics and Computing Science
		  Eindhoven University of Technology
		  P.O. Box 513, 5600 MB Eindhoven, The Netherlands
*/

#ifndef _RESPTABLE_H_
#define _RESPTABLE_H_

#ifdef _MSC_VER
#pragma warning(disable:4786) // identifier was truncated to '255'
#endif // _MSC_VER

#include "Response.h"

#include <SOLID/solid.h>
#include <map>

typedef map<DtObjectRef, Response, less<DtObjectRef> > SingleList;
typedef pair<DtObjectRef, DtObjectRef> ObjPair;
typedef map<ObjPair, Response, less<ObjPair> > PairList;

inline ObjPair make_ObjPair(DtObjectRef x, DtObjectRef y) {
  return y < x ? make_pair(y, x) : make_pair(x, y);
}

class RespTable {
public:
  const Response& find(DtObjectRef obj1, DtObjectRef obj2) const;
  void cleanObject(DtObjectRef obj);

  void setDefault(const Response& resp) { defaultResp = resp; }
  
  void setSingle(DtObjectRef obj, const Response& resp) { 
    singleList[obj] = resp; 
  }

  void resetSingle(DtObjectRef obj) { singleList.erase(obj); }
  
  void setPair(DtObjectRef obj1, DtObjectRef obj2, const Response& resp) {
    pairList[make_ObjPair(obj1, obj2)] = resp;
  }

  void resetPair(DtObjectRef obj1, DtObjectRef obj2) { 
    pairList.erase(make_ObjPair(obj1, obj2)); 
  }

    
  
private:
  Response defaultResp;
  SingleList singleList;
  PairList pairList;
};

#endif
