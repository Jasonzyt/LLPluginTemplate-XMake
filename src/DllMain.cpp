#include <Windows.h>
#include <llapi/LLAPI.h>
#include <myplugin/Resource.h>

BOOL APIENTRY DllMain(HMODULE, DWORD reasonForCall, LPVOID) {
    switch (reasonForCall) {
        case DLL_PROCESS_ATTACH:
            ll::registerPlugin(PLUGIN_NAME, PLUGIN_DESCRIPTION,
                               ll::Version(PLUGIN_VERSION_MAJOR, PLUGIN_VERSION_MINOR, PLUGIN_VERSION_PATCH,
                                           ll::Version::PLUGIN_VERSION_STATUS),
                               std::map<std::string, std::string>{{"Author", PLUGIN_AUTHOR}});
            break;
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}

namespace my_plugin {
void Entry();
}

extern "C" _declspec(dllexport) void onPostInit() {
    my_plugin::Entry();
}
