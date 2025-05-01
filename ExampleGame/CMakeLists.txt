file(GLOB_RECURSE EXAMPLE_GAME_HEADERS
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp"
)

file(GLOB_RECURSE EXAMPLE_GAME_SOURCES
        "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_executable(ExampleGame ${EXAMPLE_GAME_HEADERS} ${EXAMPLE_GAME_SOURCES})

target_include_directories(ExampleGame
        PRIVATE
        ${CMAKE_SOURCE_DIR}/BGEngine/src
        ${CMAKE_SOURCE_DIR}/BGEngine/vendor
)

target_link_libraries(ExampleGame
        PRIVATE
        BGEngine
        spdlog::spdlog
)

if(MSVC)
    target_compile_options(ExampleGame PRIVATE /utf-8)
endif()

# Optional: Set startup project in Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ExampleGame)