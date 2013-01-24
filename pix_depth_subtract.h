/*-----------------------------------------------------------------
LOG
GEM - Graphics Environment for Multimedia

Clamp pixel values to a threshold

Copyright (c) 1997-1998 Mark Danks. mark@danks.org
Copyright (c) Günther Geiger. geiger@epy.co.at
Copyright (c) 2001-2011 IOhannes m zmölnig. forum::für::umläute. IEM. zmoelnig@iem.at
Copyright (c) 2002 James Tittle & Chris Clepper
For information on usage and redistribution, and for a DISCLAIMER OF ALL
WARRANTIES, see the file, "GEM.LICENSE.TERMS" in this distribution.

-----------------------------------------------------------------*/

#ifndef _INCLUDE__GEM_PIXES_PIX_DEPTH_SUBTRACT_H_
#define _INCLUDE__GEM_PIXES_PIX_DEPTH_SUBTRACT_H_

#include "Base/GemPixObj.h"
#include <RTE/MessageCallbacks.h>


/*-----------------------------------------------------------------
-------------------------------------------------------------------
CLASS
    pix_depth_subtract
    
    Clamp pixel values to a threshold

KEYWORDS
    pix
    
DESCRIPTION

    Subtract a ref depth map to a depth stream from a Kinect sensor
   
-----------------------------------------------------------------*/
#ifdef _WIN32
class GEM_EXPORT pix_depth_subtract : public GemPixObj
#else
class GEM_EXTERN pix_depth_subtract : public GemPixObj
#endif
{
    CPPEXTERN_HEADER(pix_depth_subtract, GemPixObj);

    public:

        //////////
        // Constructor
    	pix_depth_subtract();
    	
    protected:
    	
    	//////////
    	// Destructor
    	virtual ~pix_depth_subtract();

    	//////////
    	// Do the processing
    	virtual void 	processRGBAImage(imageStruct &image);
    	

    	//////////

    	//////////
    	// Set the new threshold value
    	void	    	setrefMess(void);
    	void	    	offsetMess(float offset);

		int m_offset;
		bool m_setref;
		std::vector<int> buffer;
};

#endif	// for header file
