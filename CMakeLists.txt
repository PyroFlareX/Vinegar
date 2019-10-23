cmake_minimum_required(VERSION 3.6)

PROJECT(Vinegar)



# For Platform
if(NOT PLATFORM)
  if(CMAKE_SIZEOF_VOID_P MATCHES 8)
    set(PLATFORM 64)
  else()
    set(PLATFORM 32)
  endif()
endif()

# For Sources
file(GLOB_RECURSE header RELATIVE ${CMAKE_SOURCE_DIR} "src/*.h")
file(GLOB_RECURSE engineheader RELATIVE ${CMAKE_SOURCE_DIR} "Engine/*.h")

file(GLOB_RECURSE src RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
file(GLOB_RECURSE enginesrc RELATIVE ${CMAKE_SOURCE_DIR} "Engine/*.cpp")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(osrc ${src} "${CMAKE_SOURCE_DIR}/src/Main.cpp")
set(osrc ${osrc} "${CMAKE_SOURCE_DIR}/Engine/glad/glad.c")
add_executable(Vinegar ${src} ${header} ${osrc} ${engineheader} ${enginesrc})

# For Libraries
if(EXISTS ${CMAKE_SOURCE_DIR}/Libraries/glm/CMakeLists.txt)
    include_directories(Libraries/glm)
else()
    find_package(glm REQUIRED)
endif()

if(EXISTS ${CMAKE_SOURCE_DIR}/Libraries/glfw/CMakeLists.txt)
    add_subdirectory(Libraries/glfw)
	include_directories(Libraries/glfw/include)
else()
    find_package(glfw3 REQUIRED)
endif()

if(EXISTS ${CMAKE_SOURCE_DIR}/Libraries/openvr/CMakeLists.txt)
	set(WINDOWS_PATH_SUFFIXES win${PLATFORM} Win${PLATFORM} x${PLATFORM})

    add_subdirectory(Libraries/openvr)
	include_directories(Libraries/openvr/headers)
	find_library(OPENVR_LIBRARIES
		NAMES
			openvr_api
		PATHS
			${CMAKE_CURRENT_SOURCE_DIR}/Libraries/openvr/bin
			${CMAKE_CURRENT_SOURCE_DIR}/Libraries/openvr/lib
		PATH_SUFFIXES
			osx32
			linux64
			${WINDOWS_PATH_SUFFIXES}
		NO_DEFAULT_PATH
		NO_CMAKE_FIND_ROOT_PATH
		)
else()
    find_package(openvr_api REQUIRED)
endif()

if(EXISTS ${CMAKE_SOURCE_DIR}/Libraries/bullet3/CMakeLists.txt)
    add_subdirectory(Libraries/bullet3)
else()
    find_package(bullet3)
endif()

# For Linking
target_link_libraries(Vinegar glfw ${GLFW_LIBRARIES} ${OPENVR_LIBRARIES} 
						BulletDynamics BulletCollision LinearMath)