cmake_minimum_required(VERSION 3.31)
project(BGEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ensure vcpkg toolchain is loaded before the project() call
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Build mode flags
option(BG_DISTRIBUTION "Build for distribution" OFF)

# Add global defines based on configuration
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(BG_DEBUG)
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    add_compile_definitions(BG_RELEASE)
elseif(BG_DISTRIBUTION)
    add_compile_definitions(BG_DISTRIBUTION)
endif()

# Platform-specific defines
if(WIN32)
    add_compile_definitions(BG_PLATFORM_WINDOWS)
elseif(APPLE)
    add_compile_definitions(BG_PLATFORM_MACOS)
endif()

# Dependencies via vcpkg (manifest mode handles install)
find_package(OpenGL REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)

# Print found packages (optional debug info)
message(STATUS "Found OpenGL: ${OPENGL_FOUND}")
message(STATUS "Found GLFW3: ${glfw3_FOUND}")
message(STATUS "Found glm: ${glm_FOUND}")
message(STATUS "Found imgui: ${imgui_FOUND}")
message(STATUS "Found spdlog: ${spdlog_FOUND}")

# Subdirectories
add_subdirectory(BGEngine)
add_subdirectory(ExampleGame)
