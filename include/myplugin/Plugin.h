#pragma once
#define PLUGIN_NAME "MyPlugin"
#define PLUGIN_DESCRIPTION "My plugin description"
#define PLUGIN_AUTHOR "My name"
#define PLUGIN_VERSION_MAJOR 0
#define PLUGIN_VERSION_MINOR 1
#define PLUGIN_VERSION_PATCH 0
#define PLUGIN_VERSION_BUILD 0
#define PLUGIN_VERSION_STATUS Dev // Dev, Beta or Release
#define PLUGIN_VERSION_IS_RELEASE false
#define PLUGIN_VERSION_COMMIT_SHA "Unknown"
#define __TO_VERSION_STRING(ver) #ver
#define TO_VERSION_STRING(ver) __TO_VERSION_STRING(ver)
// clang-format off
#if PLUGIN_VERSION_BUILD > 0 && PLUGIN_VERSION_IS_RELEASE // Actions Build
#define PLUGIN_VERSION_STRING TO_VERSION_STRING(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_PATCH-build.PLUGIN_VERSION_BUILD-) PLUGIN_VERSION_COMMIT_SHA
#elif PLUGIN_VERSION_BUILD > 0 && !PLUGIN_VERSION_IS_RELEASE // Actions Build
#define PLUGIN_VERSION_STRING TO_VERSION_STRING(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_PATCH-PLUGIN_VERSION_STATUS-build.PLUGIN_VERSION_BUILD-) PLUGIN_VERSION_COMMIT_SHA
#elif PLUGIN_VERSION_BUILD == 0 && PLUGIN_VERSION_IS_RELEASE
#define PLUGIN_VERSION_STRING TO_VERSION_STRING(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_PATCH)
#elif PLUGIN_VERSION_BUILD == 0 && !PLUGIN_VERSION_IS_RELEASE
#define PLUGIN_VERSION_STRING TO_VERSION_STRING(PLUGIN_VERSION_MAJOR.PLUGIN_VERSION_MINOR.PLUGIN_VERSION_PATCH-PLUGIN_VERSION_STATUS)
#endif
// clang-format on

class Logger;

namespace my_plugin {
extern Logger logger;
}