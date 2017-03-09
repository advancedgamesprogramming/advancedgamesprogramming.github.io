
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
 * xml.h -- Interface file for XML 
 *
 * @(#) $Id: xml.h,v 1.1.1.1 2001/06/24 18:29:48 torcs Exp $
 */
 
#ifndef _XML_H_
#define _XML_H_

typedef struct xmlAttribute {
    char		*name;
    char		*value;
    struct xmlAttribute	*next;
} txmlAttribute;

typedef struct xmlElement {
    char		*name;		/* element name */
    char		*pcdata;	/* string associated with this element */
    struct xmlAttribute	*attr;		/* attributes of this element */
    int			level;		/* nested level */
    struct xmlElement	*next;		/* next element at the same level */
    struct xmlElement	*sub;		/* next element at the next level (nested) */
    struct xmlElement	*up;		/* upper element */
} txmlElement;    

extern txmlElement *xmlInsertElt(txmlElement *curElt, const char *name, const char **atts);
extern txmlElement *xmlReadFile(const char *file);
extern int          xmlWriteFile(const char *file, txmlElement *startElt, char *dtd);
extern char        *xmlGetAttr(txmlElement *curElt, char *attrname);
extern txmlElement *xmlNextElt(txmlElement *startElt);
extern txmlElement *xmlSubElt(txmlElement *startElt);
extern txmlElement *xmlWalkElt(txmlElement *startElt);
extern txmlElement *xmlWalkSubElt(txmlElement *startElt, txmlElement *topElt);
extern txmlElement *xmlFindNextElt(txmlElement *startElt, char *name);
extern txmlElement *xmlFindEltAttr(txmlElement *startElt, char *name, char *attrname, char *attrvalue);

#endif /* _XML_H_ */ 



