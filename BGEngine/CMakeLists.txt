# Add the glad source file
file(GLOB_RECURSE BG_ENGINE_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/src/glad.c"  # OnUpdate to the new location of glad.c
)

file(GLOB_RECURSE BG_ENGINE_HEADERS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)

add_library(BGEngine SHARED ${BG_ENGINE_HEADERS} ${BG_ENGINE_SOURCES})

# Precompiled headers - specifying CXX language explicitly
target_precompile_headers(BGEngine PRIVATE
        $<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/src/BGPCH.h>
)

# Include directories
target_include_directories(BGEngine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include  # Add the include directory for glad
)

# Compile definitions
target_compile_definitions(BGEngine PRIVATE
        BG_BUILD_DLL
        GLFW_INCLUDE_NONE
)

# Platform-specific OpenGL linking
if(WIN32)
    target_link_libraries(BGEngine PRIVATE opengl32)
endif()
if(APPLE)
    target_link_libraries(BGEngine PRIVATE "-framework OpenGL")
endif()

# Link dependencies
target_link_libraries(BGEngine
        PRIVATE
        OpenGL::GL
        glfw
        glm::glm
        imgui::imgui
        spdlog::spdlog
)

# Use UTF-8 for MSVC
if(MSVC)
    target_compile_options(BGEngine PRIVATE /utf-8)
endif()

# Copy DLL (for Windows-style dev setup)
add_custom_command(TARGET BGEngine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:BGEngine>
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>/ExampleGame/$<TARGET_FILE_NAME:BGEngine>
)