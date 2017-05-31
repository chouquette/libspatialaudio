/*############################################################################*/
/*#                                                                          #*/
/*#  Ambisonic C++ Library                                                   #*/
/*#  CAmbisonicZoomer - Ambisonic Zoomer                                     #*/
/*#  Copyright � 2007 Aristotel Digenis                                      #*/
/*#                                                                          #*/
/*#  Filename:      AmbisonicZoomer.h                                        #*/
/*#  Version:       0.1                                                      #*/
/*#  Date:          19/05/2007                                               #*/
/*#  Author(s):     Aristotel Digenis                                        #*/
/*#  Licence:       MIT                                                      #*/
/*#                                                                          #*/
/*############################################################################*/


#ifndef _AMBISONIC_ZOOMER_H
#define _AMBISONIC_ZOOMER_H

#include "AmbisonicBase.h"
#include "AmbisonicDecoder.h"
#include "BFormat.h"

/// Ambisonic zoomer.

/** This object is used to apply a zoom effect into BFormat soundfields. */

class CAmbisonicZoomer : public CAmbisonicBase
{
public:
    CAmbisonicZoomer();
    ~CAmbisonicZoomer();
    /**
        Re-create the object for the given configuration. Previous data is
        lost. The last argument is not used, it is just there to match with
        the base class's form. Returns true if successful.
    */
    virtual bool Configure(unsigned nOrder, bool b3D, unsigned nMisc);
    /**
        Not implemented.
    */
    void Reset();
    /**
        Recalculate coefficients.
    */
    void Refresh();
    /**
        Set zoom factor. This is in a range from -1 to 1, with 0 being no zoom,
        1 full forward zoom, and -1 full forward backwards.
    */
    void SetZoom(float fZoom);
    /**
        Get zoom factor.
    */
    float GetZoom();
    /**
        Zoom into B-Format stream.
    */
    void Process(CBFormat* pBFSrcDst, unsigned nSamples);
    /**
        Compute factorial of integer
    */
    float factorial(unsigned M);
protected:
    CAmbisonicDecoder m_AmbDecoderFront;

    float* m_AmbEncoderFront;
    float* m_AmbEncoderFront_weighted;
    float* a_m;

    float m_fZoom;
    float m_fZoomRed;
    float m_AmbFrontMic;
    float m_fZoomBlend;
};

#endif // _AMBISONIC_ZOOMER_H
