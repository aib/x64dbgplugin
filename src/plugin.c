#include "plugin.h"

#include "_plugins.h"

int pluginHandle;

PLUG_EXPORT bool pluginit(PLUG_INITSTRUCT* initStruct)
{
	pluginHandle = initStruct->pluginHandle;

	initStruct->pluginVersion = PLUGIN_VERSION;
	initStruct->sdkVersion = PLUG_SDKVERSION;
	strncpy(initStruct->pluginName, PLUGIN_NAME, sizeof(initStruct->pluginName));

	return true;
}

PLUG_EXPORT bool plugstop()
{
	return true;
}

PLUG_EXPORT void plugsetup(PLUG_SETUPSTRUCT* setupStruct)
{
	_plugin_logprintf("Hello, World!\n");
}
