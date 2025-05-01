#pragma once

#ifdef BG_PLATFORM_WINDOWS
    #ifdef BG_BUILD_DLL
        #define BG_API __declspec(dllexport)
    #else
        #define BG_API __declspec(dllimport)
    #endif
#elif BG_PLATFORM_MACOS
    #ifdef BG_BUILD_DLL
        #define BG_API __attribute__((visibility("default")))
    #else
        #define BG_API
    #endif
#else
    #error Only Windows and MacOS Support!
#endif