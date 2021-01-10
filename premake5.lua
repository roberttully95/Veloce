workspace "Veloce"
	architecture "x64"
	startproject "Sandbox"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder
IncludeDir = {};
IncludeDir["GLFW"] = "Veloce/vendor/GLFW/include"

include "Veloce/vendor/GLFW"

project "Veloce"
	location "Veloce"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "velpch.h"
	pchsource "Veloce/src/velpch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp",
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"VELOCE_PLATFORM_WINDOWS",
			"VELOCE_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "VELOCE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "VELOCE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "VELOCE_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp",
	}

	includedirs{
		"Veloce/vendor/spdlog/include",
		"Veloce/src",

	}

	links{
		"Veloce"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"VELOCE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VELOCE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "VELOCE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "VELOCE_DIST"
		runtime "Release"
		optimize "On"