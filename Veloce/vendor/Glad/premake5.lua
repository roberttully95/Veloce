project "Glad"
	kind "StaticLib"
	language "C"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"include/glad/glad.h",
		"include/KHR/khrplatform.h",
		"src/glad.c"
	}

	includedirs
	{
		"include"
	}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"
	
	filter "system:linux"
		pic "On"
		systemversion "latest"
		staticruntime "On"
	
	filter "configurations:Debug"
		buildoptions "/MTd"

	filter "configurations:Release"
		buildoptions "/MT"
