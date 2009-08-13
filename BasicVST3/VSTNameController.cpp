#include "VSTNameController.h"

VSTNameController::VSTNameController(void)
{
}

VSTNameController::~VSTNameController(void)
{
}


tresult PLUGIN_API VSTNameController::initialize(FUnknown * context)
{
	tresult result = EditController::initialize(context);
	if (result != kResultOk)
	{
		return result;
	}

	//define units, parameters etc in here

	return result;
}

tresult PLUGIN_API VSTNameController::terminate()
{
	return EditController::terminate();
}


tresult PLUGIN_API VSTNameController::setComponentState(IBStream * state)
{
	return kResultFalse;
}

/*IPlugView * PLUGIN_API VSTNameController::createView(const char * name)
{
}*/

tresult PLUGIN_API VSTNameController::setState(IBStream * state)
{
	return kResultFalse;
}

tresult PLUGIN_API VSTNameController::getState(IBStream * state)
{
	return kResultFalse;
}

tresult PLUGIN_API VSTNameController::setParamNormalized(ParamID tag, ParamValue value)
{
	return kResultFalse;
}

tresult PLUGIN_API VSTNameController::getParamStringByValue(ParamID tag, ParamValue valueNormalized, String128 string)
{
	return kResultFalse;
}

tresult PLUGIN_API VSTNameController::getParamValueByString(ParamID tag, TChar * string, ParamValue& valueNormalized)
{
	return kResultFalse;
}
