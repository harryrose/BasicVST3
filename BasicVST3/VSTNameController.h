#ifndef _VSTNAME_CONTROLLER_H_
#define _VSTNAME_CONTROLLER_H_

#include "VST/public.sdk/source/vst/vsteditcontroller.h"
using namespace Steinberg::Vst;

//Define the GUID of the Controller Component, be sure to change this to something original...

#define CONTROLLER_GUID1 0xA0D6A030
#define CONTROLLER_GUID2 0xBC4544CC
#define CONTROLLER_GUID3 0xA33ECB9E
#define CONTROLLER_GUID4 0xC4C58F85

#define CONTROLLER_GUID CONTROLLER_GUID1, CONTROLLER_GUID2,CONTROLLER_GUID3,CONTROLLER_GUID4

//DEFINE_GUID(CONTROLLER_GUID, 
//0xa0d6a030, 0xbc45, 0x44cc, 0xa3, 0x3e, 0xcb, 0x9e, 0xc4, 0xc5, 0x8f, 0x85);


class VSTNameController : public EditController //also extend other things such as IMidiMapping to get extra functionality
{
public:
	VSTNameController(void);
	
	static FUnknown * createInstance (void * context)
	{
		return (IEditController *) new VSTNameController;
	}

	tresult PLUGIN_API initialize (FUnknown * context);
	tresult PLUGIN_API terminate  ();


	tresult PLUGIN_API setComponentState (IBStream * state);

	//Uncomment if you have an editor...
	//IPlugView * PLUGIN_API createView (const char * name);
	
	tresult PLUGIN_API setState (IBStream * state);
	tresult PLUGIN_API getState (IBStream * state);
	tresult PLUGIN_API setParamNormalized (ParamID tag, ParamValue value);
	tresult PLUGIN_API getParamStringByValue (ParamID tag, ParamValue valueNormalized, String128 string);
	tresult PLUGIN_API getParamValueByString (ParamID tag, TChar * string, ParamValue& valueNormalized);

	~VSTNameController(void);
};

#endif //#ifndef _VSTNAME_CONTROLLER_H_