#pragma once

#ifdef LE_PLATFORM_WINDOWS
				#ifdef LE_BUILD_DLL
								#define LITTLE_API __declspec(dllexport)
				#else
								#define LITTLE_API __declspec(dllimport)
				#endif
#elif LE_PLATFORM_LINUX
				#ifdef LE_BUILD_DLL
								#define LITTLE_API __attribute__((visibility("default")))
				#else 
								#define LITTLE_API
				#endif
#else
    #define LITTLE_API
    #pragma warning Unknown dynamic link import/export semantics.
#endif


#define BIT(x) (1 << x)
