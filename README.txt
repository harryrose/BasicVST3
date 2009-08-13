Based (fairly heavily) on the again example provided in the VST3 SDK.

Do a project wide find and replace for VSTName and replace that with whatever you want
your VST to be called.

Don't forget to rename files/directories as necessary.

In order to compile you will need to get the VST3 API from Steinberg,
http://www.steinberg.net/en/company/3rd_party_developer.html

When you have expanded the arcives, you need to copy the following directories into the
VST directory in the project.

	/pluginterfaces
	/public.sdk
	/vstgui.sf
