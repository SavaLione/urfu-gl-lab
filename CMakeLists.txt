#################################################################################
# Copyright (c) 2022, Savely Pototsky (SavaLione)
# All rights reserved.
#################################################################################
# Checking the minimum version
cmake_minimum_required (VERSION 3.13.1)

# Add module path
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

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
find_package(GLFW REQUIRED)

# spdlog
find_package(spdlog REQUIRED)

#################################################################################
#                                     Sources                                   #
#################################################################################
# core
set(LANTHE_CORE_SRC
    src/core/compiler_version.h
    src/core/compiler_version.cpp
    src/core/lanthe.h
    src/core/lanthe.cpp
    src/core/platform.h
    src/core/platform.cpp
    src/core/settings.h
    src/core/settings.cpp
    src/core/version.h
    src/core/version.cpp
    src/core/window.h
    src/core/window.cpp
)

# time
set(LANTHE_TIME_SRC
    src/time/current_time.h
    src/time/current_time.cpp
    src/time/execution_time.h
    src/time/execution_time.cpp
    src/time/wait_time.h
    src/time/wait_time.cpp
)

# Lanthe application
set(LANTHE_SRC
    ${LANTHE_CORE_SRC}
    ${LANTHE_TIME_SRC}
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
target_link_libraries(${LANTHE_PROJECT} ${GLFW_LIBRARY})
target_include_directories(${LANTHE_PROJECT} PUBLIC ${GLFW_INCLUDE_DIR})

# spdlog
target_link_libraries(${LANTHE_PROJECT} ${SPDLOG_LIBRARY})
target_include_directories(${LANTHE_PROJECT} PUBLIC ${SPDLOG_INCLUDE_DIR})

#################################################################################
#                                 Output directory                              #
#################################################################################
function_output_directory(${LANTHE_PROJECT})    # Lanthe application