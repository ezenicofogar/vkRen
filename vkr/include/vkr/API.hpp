#pragma once
// Definition of VKR_API

#ifdef VKR_DLL
  #ifdef VKR_DLL_EXPORT
    #define VKR_API __declspec(dllexport)
  #else
    #define VKR_API __declspec(dllimport)
  #endif
#else
  #define VKR_API
#endif
