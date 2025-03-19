project "BGEngine"
	location "BGEngine"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-intermediates/" .. outputdir .. "/%{prj.name}")

	pchheader "BGPCH.h"
	pchsource "src/BGPCH.cpp"

	files{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs{
		"src",
		"vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links{
		"GLFW",
		"opengl32.lib",
        "ImGui"
	}

	filter "system:windows"
		systemversion "latest"

		defines{
			"BG_PLATFORM_WINDOWS",
			"BG_BUILD_DLL"
		}

		postbuildcommands{
            '{COPYFILE} "%{cfg.buildtarget.abspath}" "%{wks.location}/bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/ExampleGame/"'
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