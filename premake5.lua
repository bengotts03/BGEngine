workspace "BGEngine"
	architecture "x64"
	startproject "ExampleGame"

	configurations{
		"Debug",
		"Release",
		"Distribution"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "BGEngine/vendor/GLFW3/include"

include "BGEngine/vendor/GLFW3"

project "BGEngine"
	location "BGEngine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-intermediates/" .. outputdir .. "/%{prj.name}")

	pchheader "BGPCH.h"
	pchsource "BGEngine/src/BGPCH.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "off"
		systemversion "latest"

		defines{
			"BG_PLATFORM_WINDOWS",
			"BG_BUILD_DLL"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/ExampleGame")
		}

		buildoptions {"/utf-8"}

	filter "configurations:Debug"
		defines "BG_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "BG_RELEASE"
		optimize "On"
		
	filter "configurations:Distribution"
		defines "BG_DISTRIBUTION"
		optimize "On"

------------------------------------------------------------------------------------

project "ExampleGame"
	location "ExampleGame"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-intermediates/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		"BGEngine/vendor/spdlog/include",
		"BGEngine/vendor/GLFW3/include",
		"BGEngine/vendor/ImGui/",
		"BGEngine/src"
	}

	links{
		"BGEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "off"
		systemversion "latest"

		defines{
			"BG_PLATFORM_WINDOWS"
		}

		buildoptions {"/utf-8"}

	filter "configurations:Debug"
		defines "BG_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "BG_RELEASE"
		optimize "On"
		
	filter "configurations:Distribution"
		defines "BG_DISTRIBUTION"
		optimize "On"