#pragma once

#ifdef VELOCE_PLATFORM_WINDOWS
	#ifdef VELOCE_BUILD_DLL
		#define VELOCE_API __declspec(dllexport)
	#else
		#define VELOCE_API __declspec(dllimport)
	#endif
#else
	#error Veloce currently only supports Windows!
#endif

#ifdef VELOCE_ENABLE_ASSERTS
	#define VELOCE_ASSERT(x, ...) { if(!(x)) { VELOCE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define VELOCE_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define VELOCE_ASSERT(x, ...)
	#define VELOCE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << (x))
#define VELOCE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
