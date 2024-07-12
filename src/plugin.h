#ifndef PLUGIN_H__
#define PLUGIN_H__

#define PLUGIN_NAME "x64dbgplugin"
#define PLUGIN_VERSION 1

#ifdef __cplusplus
#define PLUG_EXPORT extern "C" __declspec(dllexport)
#else
#define PLUG_EXPORT __declspec(dllexport)
#endif

extern int pluginHandle;

#endif
