cmake_minimum_required(VERSION 3.18)

project(polyhook-veh-crash)

set(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")
set(PROJECT_BIN  ${PROJECT_ROOT}/bin)
set(PROJECT_LIB  ${PROJECT_ROOT}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY          ${PROJECT_BIN})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG    ${PROJECT_BIN})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE  ${PROJECT_BIN})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY          ${PROJECT_BIN})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG    ${PROJECT_BIN})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE  ${PROJECT_BIN})

find_package(PolyHook_2 CONFIG REQUIRED)

set(SOURCE_FILES
	"src/main.cpp"
    "src/stdafx.h"
)

add_executable(polyhook-veh-crash ${SOURCE_FILES})

# /MT fix
set_property(TARGET polyhook-veh-crash PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

target_link_libraries(polyhook-veh-crash PRIVATE PolyHook_2::PolyHook_2)
target_compile_features(polyhook-veh-crash PRIVATE cxx_auto_type)
target_compile_features(polyhook-veh-crash PRIVATE cxx_std_17)