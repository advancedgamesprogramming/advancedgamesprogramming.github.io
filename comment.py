
headcomment = """
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

"""

# *.h
# *.cpp

def AddHeading(fn):
	fp = open(fn, "r")
	txt = fp.read()
	fp.close()
	fp = 0
	
	txt = headcomment + txt
	fp = open(fn, "w")
	fp.write(txt)
	fp.close()
	fp = 0


totalCodeFiles = 0

import os
for root, directories, filenames in os.walk('.'):
	for directory in directories:
		os.path.join(root, directory)
	for filename in filenames: 
		fn = os.path.join(root,filename) 
		if (".h" in fn) or (".cpp" in fn):
		#if ("aa.aaa.txt" in fn):
			print fn
			totalCodeFiles+=1
			AddHeading(fn)
			
print "Total Code Files: " + str(totalCodeFiles)





