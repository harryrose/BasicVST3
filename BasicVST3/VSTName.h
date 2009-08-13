/*
 * A Basic Shell of a VST.  This is based v heavily on the "again" example provided
 * in the Steinberg VST 3 API.
 */

#ifndef _VSTNAME_H_
#define _VSTNAME_H_

#include "VST/public.sdk/source/vst/vstaudioeffect.h"

//Define the GUID of the VST Plugin.  Change this to something unique.

#define PLUGIN_GUID1 0xA8E29FFF
#define PLUGIN_GUID2 0x77E24203
#define PLUGIN_GUID3 0x97D7D1B5
#define PLUGIN_GUID4 0xD77767F4

#define PLUGIN_GUID PLUGIN_GUID1,PLUGIN_GUID2,PLUGIN_GUID3,PLUGIN_GUID4


using namespace Steinberg::Vst;

class VSTName : public AudioEffect
{
public:
	VSTName(void);

	static FUnknown * createInstance(void * context)
	{
		return (IAudioProcessor*) new VSTName();
	}

	//called after the constructor
	tresult PLUGIN_API initialize(FUnknown * context);

	//called before the destructor
	tresult PLUGIN_API terminate();

	//turns the effect on/off
	tresult PLUGIN_API setActive(TBool state);

	//Called before the first process call
	tresult PLUGIN_API setupProcessing(ProcessSetup& newSetup);

	//This is where we process the sound/events
	tresult PLUGIN_API process(ProcessData& data);

	/** for persistence (apparently).  Will have to read more about this, presumably
	this gets or sets the state of the instrument so it can be resumed later? **/
	tresult PLUGIN_API setState(IBStream * state);
	tresult PLUGIN_API getState(IBStream * state);
	
	//Sorts out inputs and outputs etc.
	tresult PLUGIN_API setBusArrangements(SpeakerArrangement * inputs, int32 numIns, SpeakerArrangement * outputs, int32 numOuts);
	~VSTName(void);
};


#endif //#ifndef _VSTNAME_H_