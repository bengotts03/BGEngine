project "ExampleGame"
	kind "ConsoleApp"
	language "C++"
    staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-intermediates/" .. outputdir .. "/%{prj.name}")

	files{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs{
		"%{wks.location}/BGEngine/vendor/spdlog/include",
		"%{wks.location}/BGEngine/src",
		"%{wks.location}/BGEngine/vendor"
	}

	links{
		"BGEngine"
	}

	filter "system:windows"
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