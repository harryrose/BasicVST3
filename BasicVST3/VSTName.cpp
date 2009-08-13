//Keep this in, I was debugging linker errors for ages until I spotted this...
#define INIT_CLASS_IID

#include "VSTName.h"

#include "VSTNameController.h"
#include "VST/pluginterfaces/base/ibstream.h"
VSTName::VSTName(void)
{
	setControllerClass(FUID(CONTROLLER_GUID));
}

VSTName::~VSTName(void)
{
}


tresult PLUGIN_API VSTName::initialize(FUnknown * context)
{
	tresult result = AudioEffect::initialize(context);	
	if (result != kResultOk)
	{
		return result;
	}

	//add audio+event input/outputs

}

//called before the destructor
tresult PLUGIN_API VSTName::terminate()
{
	return AudioEffect::terminate();
}

//turns the effect on/off
tresult PLUGIN_API VSTName::setActive(TBool state)
{
	return kResultFalse;
}

//Called before the first process call
tresult PLUGIN_API VSTName::setupProcessing(ProcessSetup& newSetup)
{
	//newsetup.processMode tells us whate processing mode we should be in now.
	return AudioEffect::setupProcessing(newSetup);
}

//This is where we process the sound/events
tresult PLUGIN_API VSTName::process(ProcessData& data)
{
	//From the Steinberg API

	// finally the process function
	// In this example there are 4 steps:
	// 1) Read inputs parameters coming from host (in order to adapt our model values)
	// 2) Read inputs events coming from host (we apply a gain reduction depending of the velocity of pressed key)
	// 3) Process the gain of the input buffer to the output buffer
	// 4) Write the new VUmeter value to the output Parameters queue

	return kResultFalse;
}

/** for persistence (apparently).  Will have to read more about this, presumably
this gets or sets the state of the instrument so it can be resumed later? **/
tresult PLUGIN_API VSTName::setState(IBStream * state)
{
	return kResultFalse;
}

tresult PLUGIN_API VSTName::getState(IBStream * state)
{
	return kResultFalse;
}

//Sorts out inputs and outputs etc.
tresult PLUGIN_API VSTName::setBusArrangements(SpeakerArrangement * inputs, int32 numIns, SpeakerArrangement * outputs, int32 numOuts)
{
	return kResultFalse;
}
