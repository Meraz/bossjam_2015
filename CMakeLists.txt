# CMake settings
cmake_minimum_required(VERSION 3.0.2)

# define a macro that helps defining an option
macro(set_option var default type docstring)
    if(NOT DEFINED ${var})
        set(${var} ${default})
    endif()
    set(${var} ${${var}} CACHE ${type} ${docstring} FORCE)
endmacro()

set(SOLUTION_NAME bossjam_2015)
project(${SOLUTION_NAME})

option(COMPILE_RELEASE_BUILD "Unchecked is debug" OFF)

set(OUTPUT_FOLDER ${CMAKE_BINARY_DIR}/build)
set(OUTPUT_FOLDER ${OUTPUT_FOLDER}/32)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_FOLDER})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_FOLDER})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_FOLDER})

# Path for copying .dll to correct folder
if(COMPILE_RELEASE_BUILD)
	set(OUTPUT_FOLDER ${OUTPUT_FOLDER}/Release)	
else()
	set(OUTPUT_FOLDER ${OUTPUT_FOLDER}/Debug)
endif()

# Find external libraries and modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/Modules/")
include(create_source_group)

# SFML paths and libs
set(SFML_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/SFML/include)
if(COMPILE_RELEASE_BUILD)
	set(SFML_LIBRARIES sfml-audio.lib sfml-graphics.lib sfml-main.lib sfml-network.lib sfml-system.lib sfml-window.lib)	
else()
	set(SFML_LIBRARIES sfml-audio-d.lib sfml-graphics-d.lib sfml-main-d.lib sfml-network-d.lib sfml-system-d.lib sfml-window-d.lib)	
endif()

#find_package(DIRECTX11 REQUIRED)
set(EXTERNAL_INCLUDE_DIRS 
#	${DIRECTX11_INCLUDE_DIRS}
)

set(EXTERNAL_LIBRARIES_ALL
#	${DIRECTX11_LIBRARY}
#	${DIRECTX11_COMPILER_LIBRARY}
#	${DIRECTX11_DXGUID_LIBRARY}
)

include_directories(${SFML_INCLUDE_DIR})
include_directories(${EXTERNAL_INCLUDE_DIRS})

# Add SFML
add_subdirectory(SFML)

# Set global compiler options
add_definitions(-DUNICODE -D_UNICODE)
#add_definitions(-D_USE_MATH_DEFINES)
#add_definitions(-D_SCL_SECURE_NO_WARNINGS)

# Add subdirectories
add_subdirectory(Dependencies)
add_subdirectory(Game)

# Copy game resources
add_custom_target(_resourceCopy ALL 
#	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/bossjam_2015_assets ${CMAKE_BINARY_DIR}/Game
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/bossjam_2015_assets ${OUTPUT_FOLDER}
)

# Set the default configuration
if (COMPILE_RELEASE_BUILD)
    set(CMAKE_BUILD_TYPE "Release")
else()
    set(CMAKE_BUILD_TYPE "Debug")
endif()
set(CMAKE_CONFIGURATION_TYPES ${CMAKE_BUILD_TYPE} CACHE STRING "" FORCE)