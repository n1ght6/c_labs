#ifndef DYNAMIC_UTILS_H
#define DYNAMIC_UTILS_H

#ifdef _WIN32
    #ifdef DYNAMIC_UTILS_EXPORTS
        #define DYNAMIC_API __declspec(dllexport)
    #else
        #define DYNAMIC_API __declspec(dllimport)
    #endif
#else
    #define DYNAMIC_API __attribute__((visibility("default")))
#endif

DYNAMIC_API void DynamicHello();

#endif
