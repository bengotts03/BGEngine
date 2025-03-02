workspace "BGEngine"
	architecture "x64"
	startproject "ExampleGame"

	configurations{
		"Debug",
		"Release",
		"Distribution"
	}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "BGEngine"
	location "BGEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-intermediates/" .. outputDir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		--"BGEngine/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"BG_PLATFORM_WINDOWS",
			"BG_BUILD_DLL"
		}

		postbuildcommands{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Game")
		}

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

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-intermediates/" .. outputDir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{
		--"BGEngine/vendor/spdlog/include",
		"BGEngine/src"
	}

	links{
		"BGEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
			"BG_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "BG_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "BG_RELEASE"
		optimize "On"
		
	filter "configurations:Distribution"
		defines "BG_DISTRIBUTION"
		optimize "On"