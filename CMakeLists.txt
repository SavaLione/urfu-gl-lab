#################################################################################
# Copyright (c) 2022, Savely Pototsky (SavaLione)
# All rights reserved.
#################################################################################
# Checking the minimum version
cmake_minimum_required (VERSION 3.13.1)

# Project Lanthe
set(LANTHE_PROJECT "lanthe")
set(LANTHE_PROJECT_VERSION "0.0.1")

project(${LANTHE_PROJECT}
    VERSION ${LANTHE_PROJECT_VERSION}
    LANGUAGES CXX
)

# flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")               # default
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")           # debug

#################################################################################
#                               Macros and functions                            #
#################################################################################
# Output directory
function(function_output_directory arg_project)
    set_target_properties(${arg_project}
        PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # lib
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" # lib
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
endfunction(function_output_directory)

#################################################################################
#                                    Libraries                                  #
#################################################################################
# OpenGL
find_package(OpenGL REQUIRED)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)

set(GLFW_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/glfw/include" CACHE PATH "GLFW lib include")
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/glfw)

# imgui
set(IMGUI_BUILD_BACKEND_OPENGL3 ON CACHE BOOL "" FORCE)
set(IMGUI_BUILD_BACKEND_GLFW ON CACHE BOOL "" FORCE)

set(IMGUI_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/imgui/include" CACHE PATH "imgui lib include")
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/imgui)

# spdlog
set(SPDLOG_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/spdlog/include" CACHE PATH "spdlog lib include")
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/spdlog)

# tinyfiledialogs
set(TFD_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/lib/tinyfiledialogs/include" CACHE PATH "tinyfiledialogs lib include")
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/tinyfiledialogs)

#################################################################################
#                                     Sources                                   #
#################################################################################
# core
set(LANTHE_CORE_SRC
    src/core/lanthe.h
    src/core/lanthe.cpp
)

# Lanthe application
set(LANTHE_SRC
    ${LANTHE_CORE_SRC}
)

#################################################################################
#                                     Executable                                #
#################################################################################
add_executable(${LANTHE_PROJECT} ${LANTHE_SRC})
target_include_directories(${LANTHE_PROJECT} PUBLIC ${PROJECT_SOURCE_DIR}/src)

# C++ features
target_compile_features(${LANTHE_PROJECT} PRIVATE cxx_auto_type)

#################################################################################
#                                Libraries include                              #
#################################################################################
# OpenGL
target_link_libraries(${LANTHE_PROJECT} ${OPENGL_gl_LIBRARY})
target_include_directories(${LANTHE_PROJECT} PUBLIC ${OPENGL_INCLUDE_DIR})

# GLFW
target_link_libraries(${LANTHE_PROJECT} glfw)
target_include_directories(${LANTHE_PROJECT} PUBLIC ${GLFW_INCLUDE_DIR})

# spdlog
target_link_libraries(${LANTHE_PROJECT} spdlog)
target_include_directories(${LANTHE_PROJECT} PUBLIC ${SPDLOG_INCLUDE_DIR})

#################################################################################
#                                 Output directory                              #
#################################################################################
function_output_directory(glfw)                 # Library glfw output directory
function_output_directory(spdlog)               # Library spdlog output directory
function_output_directory(${LANTHE_PROJECT})    # Lanthe application