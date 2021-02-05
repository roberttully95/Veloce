workspace "Veloce"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder
IncludeDir = {};
IncludeDir["GLFW"] = "Veloce/vendor/GLFW/include"
IncludeDir["Glad"] = "Veloce/vendor/Glad/include"
IncludeDir["ImGui"] = "Veloce/vendor/imgui"
IncludeDir["glm"] = "Veloce/vendor/glm"

include "Veloce/vendor/GLFW"
include "Veloce/vendor/Glad"
include "Veloce/vendor/imgui"

project "Veloce"
	location "Veloce"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "velpch.h"
	pchsource "Veloce/src/velpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"VELOCE_PLATFORM_WINDOWS",
			"VELOCE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "VELOCE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VELOCE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VELOCE_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"Veloce/vendor/spdlog/include",
		"Veloce/src",
		"Veloce/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Veloce"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"VELOCE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VELOCE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VELOCE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VELOCE_DIST"
		runtime "Release"
		optimize "on"