
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

class ssgGrVtxArray : public ssgVtxArray
{
protected:
  ssgIndexArray      *indices;

  virtual void draw_geometry () ;
  virtual void copy_from ( ssgGrVtxArray *src, int clone_flags ) ;

public:
  virtual ssgBase *clone ( int clone_flags = 0 ) ;
  ssgGrVtxArray () ;
  ssgGrVtxArray ( GLenum ty, ssgVertexArray   *vl,
                           ssgNormalArray   *nl,
                           ssgTexCoordArray *tl,
                           ssgColourArray   *cl,
		           ssgIndexArray    *il ) ;

  virtual void drawHighlight ( sgVec4 colour ) ;
  virtual void drawHighlight ( sgVec4 colour, int i ) ;
  virtual void pick ( int baseName ) ;

  void setIndices ( ssgIndexArray *il ) ;

  int getNumIndices () { return indices -> getNum () ; }

  int getNumTriangles () { return ssgVtxArray::getNumTriangles();}
  void getTriangle ( int n, short *v1, short *v2, short *v3 )  { ssgVtxArray::getTriangle(n,v1,v2,v3);}

  int  getNumLines () {return ssgVtxArray::getNumLines();}
  void getLine ( int n, short *v1, short *v2 ) { ssgVtxArray::getLine(n,v1,v2);}

  void getIndexList ( void **list ) { *list = indices  -> get ( 0 ) ; }

  short *getIndex  (int i){ if(i>=getNumIndices())i=getNumIndices()-1;
                             return (getNumIndices()<=0) ?
				      &_ssgIndex0 : indices->get(i);}

  virtual ~ssgVtxArray (void) ;

  virtual char *getTypeName(void) { return ssgVtxArray::getTypeName();}

  virtual void print ( FILE *fd = stderr, char *indent = "", int how_much = 2 ) { ssgVtxArray::print(fd,indent,how_much);}
  virtual int load ( FILE *fd ) {return  ssgVtxArray::load(fd);}
  virtual int save ( FILE *fd ) {return  ssgVtxArray::save(fd);}
} ;
