#pragma once

#ifdef VEL_PLATFORM_WINDOWS
	#ifdef VELOCE_BUILD_DLL
		#define VELOCE_API __declspec(dllexport)
	#else
		#define VELOCE_API __declspec(dllimport)
	#endif
#else
	#error Veloce currently only supports Windows!
#endif

#define BIT(x) (1 << x) 