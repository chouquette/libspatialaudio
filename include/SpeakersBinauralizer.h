#ifndef BINAURALIZER_H
#define BINAURALIZER_H

#include <vector>

#include "AmbisonicCommons.h"
#include "BFormat.h"
#include "AmbisonicSpeaker.h"
#include "AmbisonicBinauralizer.h"


/** Binaural decoder. */

class SpeakersBinauralizer : public CAmbisonicBinauralizer
{
public:
    bool Configure(unsigned nSampleRate,
                   unsigned nBlockSize,
                   CAmbisonicSpeaker *speakers,
                   unsigned nSpeakers,
                   unsigned& tailLength,
                   std::string HRTFPath = "");

    void Process(float** pBFSrc, float** ppfDst);

protected:
    CAmbisonicSpeaker *m_speakers;
    unsigned m_nSpeakers;

    virtual void AllocateBuffers();
    virtual void DeallocateBuffers();
};

#endif // BINAURALIZER_H
