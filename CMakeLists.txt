# CMake settings
cmake_minimum_required(VERSION 2.8)

set(SOLUTION_NAME bossjam_2015)
project(${SOLUTION_NAME})

option(COMPILE_RELEASE_BUILD "Unchecked is debug" OFF)
option(COMPILE_64_BIT_BUILD "Unchecked is 32 bit" OFF)

set(OUTPUT_FOLDER ${CMAKE_BINARY_DIR}/build)

if(COMPILE_64_BIT_BUILD)
	set(OUTPUT_FOLDER ${OUTPUT_FOLDER}/64)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_FOLDER})
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_FOLDER})
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_FOLDER})
	set(EXTERNAL_DLLS ${CMAKE_SOURCE_DIR}/External/dll/x64)
	else()
	set(OUTPUT_FOLDER ${OUTPUT_FOLDER}/32)
	set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_FOLDER})
	set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_FOLDER})
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_FOLDER})
	set(EXTERNAL_DLLS ${CMAKE_SOURCE_DIR}/External/dll/x86)
endif()

# Path for copying .dll to correct folder
if(COMPILE_RELEASE_BUILD)
	set(OUTPUT_FOLDER ${OUTPUT_FOLDER}/Release)	
	set(EXTERNAL_DLLS ${EXTERNAL_DLLS}/Release)
else()
	set(OUTPUT_FOLDER ${OUTPUT_FOLDER}/Debug)
	set(EXTERNAL_DLLS ${EXTERNAL_DLLS}/Debug)
endif()

# Find external libraries and modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/Modules/")
#include(create_source_group)

#find_package(DIRECTX11 REQUIRED)

set(EXTERNAL_INCLUDE_DIRS 
#	${DIRECTX11_INCLUDE_DIRS}
)

set(EXTERNAL_LIBRARIES_ALL
#	${DIRECTX11_LIBRARY}
#	${DIRECTX11_COMPILER_LIBRARY}
#	${DIRECTX11_DXGUID_LIBRARY}
)
set(EXTERNAL_LIBRARIES_GRAPHICS
#	${DIRECTX11_LIBRARY}
#	${DIRECTX11_COMPILER_LIBRARY}
#${DIRECTX11_DXGUID_LIBRARY}
)

# Set global compiler options
add_definitions(-DUNICODE -D_UNICODE)
add_definitions(-D_USE_MATH_DEFINES)
add_definitions(-D_SCL_SECURE_NO_WARNINGS)

include_directories(${EXTERNAL_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR})

# Add subdirectories
add_subdirectory(SFML)

# Copy game resources
add_custom_target(_resourceCopy ALL 
#	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Resources ${CMAKE_BINARY_DIR}/RTS		# I would love to move this to below line for debug
#	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Resources ${OUTPUT_FOLDER}
)

# Move external dlls to executing folder
add_custom_target(_dependencies ALL COMMAND ${CMAKE_COMMAND} -E copy_directory ${EXTERNAL_DLLS} ${OUTPUT_FOLDER})

# Set the default configuration
if (COMPILE_RELEASE_BUILD)
    set(CMAKE_BUILD_TYPE "Release")
else()
    set(CMAKE_BUILD_TYPE "Debug")
endif()
set(CMAKE_CONFIGURATION_TYPES ${CMAKE_BUILD_TYPE} CACHE STRING "" FORCE)