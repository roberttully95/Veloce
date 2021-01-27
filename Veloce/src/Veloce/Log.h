#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Veloce
{
	class VELOCE_API Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core log macros
#define VELOCE_CORE_TRACE(...)	::Veloce::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VELOCE_CORE_INFO(...)	::Veloce::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VELOCE_CORE_WARN(...)	::Veloce::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VELOCE_CORE_ERROR(...)	::Veloce::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VELOCE_CORE_FATAL(...)	::Veloce::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define VELOCE_TRACE(...)	::Veloce::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VELOCE_INFO(...)		::Veloce::Log::GetClientLogger()->info(__VA_ARGS__)
#define VELOCE_WARN(...)		::Veloce::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VELOCE_ERROR(...)	::Veloce::Log::GetClientLogger()->error(__VA_ARGS__)
#define VELOCE_FATAL(...)	::Veloce::Log::GetClientLogger()->fatal(__VA_ARGS__)