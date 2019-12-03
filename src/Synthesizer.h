#pragma once
#ifdef __WINDOWS_MM__
#include <windows.h>   /* required before including mmsystem.h */
#include <mmsystem.h>  /* multimedia functions (such as MIDI) for Windows */
#include <chrono>
#include <thread>
#endif
#include <iostream>
#include "RtMidi.h"
class Synthesizer
{
public:
	Synthesizer(int intrument=0);
    void spela(int hoejd, int laengd,int volym);
private:
    int hoejdtomidi(int hoejd);
private:
//	HMIDIOUT device;
    RtMidiOut *midiout;
    std::vector<unsigned char> message;
};

