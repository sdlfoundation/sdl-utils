cmake_minimum_required(VERSION 3.2)

project(sdlutils VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES Source/SDLUtils.cpp)

add_library(sdlutils STATIC ${SOURCES})

set_target_properties(sdlutils PROPERTIES
    VERSION ${PROJECT_VERSION}
    OUTPUT_NAME "sdlutils"
)

target_include_directories(sdlutils PUBLIC Include)
target_include_directories(sdlutils PUBLIC Source)
