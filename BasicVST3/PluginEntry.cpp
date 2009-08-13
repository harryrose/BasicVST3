/**This is mostly from the Steinberg API **/
#include "VSTName.h"
#include "VSTNameController.h"

#include "VST/public.sdk/source/main/pluginfactory.h"

#define stringPluginName "VSTName"

#define PLUGINVERSION "1.0.0"
void* hInstance = 0;

bool InitModule ()   
{
	extern void* moduleHandle;
	hInstance = moduleHandle;
	return true; 
}


bool DeinitModule ()
{
	return true; 
}

BEGIN_FACTORY_DEF ("COMPANY", 
			   "WEBSITE", 
			   "CONTACT")

	//---First Plug-in included in this factory-------
	// its kVstAudioEffectClass component
	DEF_CLASS2 (INLINE_UID(PLUGIN_GUID1,PLUGIN_GUID2,PLUGIN_GUID3,PLUGIN_GUID4),
				PClassInfo::kManyInstances,	// cardinality  
				kVstAudioEffectClass,		// the component category (dont changed this)
				stringPluginName,			// here the plug-in name (to be changed)
				Vst::kDistributable,	// means that component and controller could be distributed on different computers
				"Fx",					// Subcategory for this plug-in (to be changed)
				PLUGINVERSION,		// plug-in version (to be changed)
				kVstVersionString,		// the VST 3 SDK version (dont changed this, use always this define)
				VSTName::createInstance)	// function pointer called when this component should be instanciated

	// its kVstComponentControllerClass component
	DEF_CLASS2 (INLINE_UID(CONTROLLER_GUID1,CONTROLLER_GUID2,CONTROLLER_GUID3,CONTROLLER_GUID4),
				PClassInfo::kManyInstances,  // cardinality   
				kVstComponentControllerClass,// the Controller category (dont changed this)
				stringPluginName "Controller",	// controller name (could be the same than component name)
				0,						// not used here
				"",						// not used here
				PLUGINVERSION,		// plug-in version (to be changed)
				kVstVersionString,		// the VST 3 SDK version (dont changed this, use always this define)
				VSTNameController::createInstance)// function pointer called when this component should be instanciated

	//----for others plug-ins contained in this factory, put like for the first plug-in different DEF_CLASS2---

END_FACTORY
