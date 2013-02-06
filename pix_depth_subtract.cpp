////////////////////////////////////////////////////////
//
// GEM - Graphics Environment for Multimedia
//
// zmoelnig@iem.kug.ac.at
//
// Implementation file
//
//    Copyright (c) 1997-1998 Mark Danks.
//    Copyright (c) Günther Geiger.
//    Copyright (c) 2001-2011 IOhannes m zmölnig. forum::für::umläute. IEM. zmoelnig@iem.at
//    For information on usage and redistribution, and for a DISCLAIMER OF ALL
//    WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.
//
/////////////////////////////////////////////////////////


#include "pix_depth_subtract.h"
#include <stdio.h>

CPPEXTERN_NEW(pix_depth_subtract);

/////////////////////////////////////////////////////////
//
// pix_depth_subtract
//
/////////////////////////////////////////////////////////
// Constructor
//
/////////////////////////////////////////////////////////
pix_depth_subtract :: pix_depth_subtract() : m_offset(100.), m_setref(true)
{
}

/////////////////////////////////////////////////////////
// Destructor
//
/////////////////////////////////////////////////////////
pix_depth_subtract :: ~pix_depth_subtract()
{ }

/////////////////////////////////////////////////////////
// processImage
//
/////////////////////////////////////////////////////////
void pix_depth_subtract :: processRGBAImage(imageStruct &image)
{
    int datasize = image.xsize * image.ysize;
    int i; 
   

    unsigned char *base = image.data;
    
    int value = 0;
    int userid = 0;
    if ( m_setref ){
		buffer.clear();
		for(i=0; i<datasize ; i++)
		{
			value = ((int)base[chRed] << 8) + (int)base[chGreen];
			buffer.push_back(value);
		}
		m_setref = false;
	}
	
	for(i=0; i<datasize ; i++)    {
		value = ((int)base[chRed] << 8) + (int)base[chGreen];
        
         if ( value < buffer[i] - m_offset ) {
			base[chRed] = 0;
			base[chGreen] = 0;
			base[chBlue] = 0;
			base[chAlpha] = 0;
		}
	
            
		base += 4;
    }    
}


void pix_depth_subtract :: setrefMess(void)
{
    // copy current depth map to buf
    m_setref = true;
}

void pix_depth_subtract :: offsetMess(float offset)
{
    // copy current depth map to buf
    m_offset = (int) offset;
}


/////////////////////////////////////////////////////////
// static member function
//
/////////////////////////////////////////////////////////
void pix_depth_subtract :: obj_setupCallback(t_class *classPtr)
{
	CPPEXTERN_MSG0(classPtr, "setref",	setrefMess);
	CPPEXTERN_MSG1(classPtr, "offset",	offsetMess, float);
	
	printf("pix_opencv_subtract by Antoine Villeret - 2013\n");
	printf("\t build on %s, %s\n", __DATE__, __TIME__);
}
