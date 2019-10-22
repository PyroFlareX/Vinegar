cmake_minimum_required(VERSION 3.6)

PROJECT(Vinegar)


file(GLOB_RECURSE header RELATIVE ${CMAKE_SOURCE_DIR} "src/*.h")
file(GLOB_RECURSE engineheader RELATIVE ${CMAKE_SOURCE_DIR} "Engine/*.h")

file(GLOB_RECURSE src RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
file(GLOB_RECURSE enginesrc RELATIVE ${CMAKE_SOURCE_DIR} "Engine/*.cpp")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(osrc ${src} "${CMAKE_SOURCE_DIR}/src/Main.cpp")
add_executable(Vinegar ${src} ${header} ${osrc} ${engineheader} ${enginesrc})


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
    add_subdirectory(Libraries/openvr)
	include_directories(Libraries/openvr/headers)
else()
    find_package(OpenVR REQUIRED)
endif()

if(EXISTS ${CMAKE_SOURCE_DIR}/Libraries/bullet3/CMakeLists.txt)
    add_subdirectory(Libraries/bullet3)
else()
    find_package(bullet3)
endif()

target_link_libraries(Vinegar ${LIBS})