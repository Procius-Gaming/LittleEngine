#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Little {

	class LITTLE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; } 
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};


}

// core log macro
#define LE_CORE_ERROR(...) 		::Little::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LE_CORE_WARN(...) 		::Little::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LE_CORE_INFO(...) 		::Little::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LE_CORE_TRACE(...) 		::Little::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LE_CORE_FATAL(...) 		::Little::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macro
#define LE_ERROR(...)  			::Little::Log::GetClientLogger()->error(__VA_ARGS__)   
#define LE_WARN(...)   			::Little::Log::GetClientLogger()->warn(__VA_ARGS__)    
#define LE_INFO(...)   			::Little::Log::GetClientLogger()->info(__VA_ARGS__)    
#define LE_TRACE(...)  			::Little::Log::GetClientLogger()->trace(__VA_ARGS__)   
#define LE_FATAL(...)  			::Little::Log::GetClientLogger()->fatal(__VA_ARGS__)
