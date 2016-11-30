/*############################################################################*/
/*#                                                                          #*/
/*#  Ambisonic C++ Library                                                   #*/
/*#  CBFormat - Ambisonic BFormat                                            #*/
/*#  Copyright � 2007 Aristotel Digenis                                      #*/
/*#                                                                          #*/
/*#  Filename:      BFormat.h                                                #*/
/*#  Version:       0.1                                                      #*/
/*#  Date:          19/05/2007                                               #*/
/*#  Author(s):     Aristotel Digenis                                        #*/
/*#  Licence:       MIT                                                      #*/
/*#                                                                          #*/
/*############################################################################*/


#ifndef _BFORMAT_H
#define	_BFORMAT_H

#include "AmbisonicBase.h"

/// Storage for BFormat signals.

/** This object is used to store and transfer BFormat signals. Memory is 
	allocated for the number of channels needed for the given Ambisonic
	configuration (order and 2D/3D) and the number of samples. */

class CBFormat : public CAmbisonicBase
{
public:
	/**
		Constructor that allows for the format to be specified. If the format
		arguments are not specified, the values set for ::DEFAULT_ORDER, 
		::DEFAULT_HEIGHT, and ::DEFAULT_BFORMAT_SAMPLECOUNT will be used 
		instead.	
	*/
	CBFormat(AmbUInt nOrder = DEFAULT_ORDER, AmbBool b3D = DEFAULT_HEIGHT, AmbUInt nSampleCount = DEFAULT_BFORMAT_SAMPLECOUNT);
	~CBFormat();
	/**
		Returns the number of samples.
	*/
	AmbUInt GetSampleCount();
	/**
		Re-create the buffers needed for the given configuration. Previous 
		buffer contents are lost.
	*/
	bool Create(AmbUInt nOrder, AmbBool b3D, AmbUInt nSampleCount);
	/**
		Fill the buffer with zeros.
	*/
	void Reset();
	/**
		Not implemented.
	*/
	void Refresh();
	/**
		Copy a number of samples to a specific channel of the BFormat.
	*/
	void InsertStream(AmbFloat* pfData, AmbUInt nChannel, AmbUInt nSamples);
	/**
		Copy a number of samples from a specific channel of the BFormat.
	*/
	void ExtractStream(AmbFloat* pfData, AmbUInt nChannel, AmbUInt nSamples);

	/**
		Copy the content of the buffer. It is assumed that the two objects are
		of the same configuration.
	*/
	void operator = (const CBFormat &bf);
	/**
		Returns true if the configuration of the two objects match.
	*/
	AmbBool operator == (const CBFormat &bf);
	/**
		Returns true if the configuration of the two objects don't match.
	*/
	AmbBool operator != (const CBFormat &bf);
	CBFormat& operator += (const CBFormat &bf);
	CBFormat& operator -= (const CBFormat &bf);
	CBFormat& operator *= (const CBFormat &bf);
	CBFormat& operator /= (const CBFormat &bf);
	CBFormat& operator += (const AmbFloat &fValue);
	CBFormat& operator -= (const AmbFloat &fValue);
	CBFormat& operator *= (const AmbFloat &fValue);
	CBFormat& operator /= (const AmbFloat &fValue);
	
protected:
	AmbUInt m_nSamples;
	AmbUInt m_nDataLength;
	AmbFloat* m_pfData;
	AmbFloat** m_ppfChannels;

	//friend classes cannot be pure abstract type, 
	//so must list each friend class manually
	friend class CAmbisonicEncoder;
	friend class CAmbisonicEncoderDist;
	friend class CAmbisonicDecoder;
	friend class CAmbisonicSpeaker;
	friend class CAmbisonicMicrophone;
	friend class CAmbisonicProcessor;
	friend class CAmbisonicBinauralizer;
	friend class CAmbisonicZoomer;
};

#endif //_BFORMAT_H