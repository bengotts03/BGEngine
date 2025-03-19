include "ProjectDependencies.lua"

workspace "BGEngine"
	architecture "x64"
	startproject "ExampleGame"

	configurations{
		"Debug",
		"Release",
		"Distribution"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	--include "vendor/bin/premake"
	include "BGEngine/vendor/GLFW3"
	include "BGEngine/vendor/ImGui"
	--include "BGEngine/vendor/Glad"
group ""

group "Core"
	include "BGEngine"
group ""

group "Misc"
	include "ExampleGame"
group ""