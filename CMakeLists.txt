cmake_minimum_required(VERSION 3.2)

project(sdl-utils VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES Source/SDLUtils.cpp)

add_library(sdl-utils STATIC ${SOURCES})

set_target_properties(sdl-utils PROPERTIES
    VERSION ${PROJECT_VERSION}
    OUTPUT_NAME "sdl-utils"
)

target_include_directories(sdl-utils PUBLIC Include)
target_include_directories(sdl-utils PRIVATE Source)
