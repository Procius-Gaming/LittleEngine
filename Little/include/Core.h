#pragma once

#ifdef LE_PLATFORM_WINDOWS
#if LE_DYNAMIC_LINK
				#ifdef LE_BUILD_DLL
								#define LITTLE_API __declspec(dllexport)
				#else
								#define LITTLE_API __declspec(dllimport)
				#endif
#else
	#define LITTLE_API
#endif
#elif LE_PLATFORM_LINUX
#if LE_DYNAMIC_LINK
				#ifdef LE_BUILD_DLL
								#define LITTLE_API __attribute__((visibility("default")))
				#else 
								#define LITTLE_API
				#endif
#else
	#define LITTLE_API
#endif
#else
    #define LITTLE_API
    #pragma warning Unknown dynamic link import/export semantics.
#endif

#include "embed_breakpoint.h"
#ifdef LE_ENABLE_ASSERTS
	#ifdef LE_PLATFORM_WINDOWS
		#define LE_ASSERT(x, ...) { if(!(x)) {LE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
    	#define LE_CORE_ASSERT(x, ...) { if(!(x)) { LE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#elif LE_PLATFORM_LINUX
		#define LE_ASSERT(x, ...) { if(!(x)) {LE_ERROR("Assertion Failed: {0}", __VA_ARGS__); EMBED_BREAKPOINT; }}
       #define LE_CORE_ASSERT(x, ...) { if(!(x)) { LE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); EMBED_BREAKPOINT;}}
	#endif

#endif


#define BIT(x) (1 << x)

#define LE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
