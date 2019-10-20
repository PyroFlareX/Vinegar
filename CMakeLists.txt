cmake_minimum_required(VERSION 3.12.2)

PROJECT(Vinegar)

file(GLOB_RECURSE src RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
file(GLOB_RECURSE src RELATIVE ${CMAKE_SOURCE_DIR} "Engine/*.cpp")

file(GLOB_RECURSE src RELATIVE ${CMAKE_SOURCE_DIR} "src/*.h")
file(GLOB_RECURSE src RELATIVE ${CMAKE_SOURCE_DIR} "Engine/*.h")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(src ${src} "${CMAKE_SOURCE_DIR}/src/Main.cpp")
add_executable(Vinegar ${src})


if(EXISTS ${CMAKE_SOURCE_DIR}/Libraries/glm/CMakeLists.txt)
    add_subdirectory(Libraries/glm)
else()
    find_package(glm REQUIRED)
endif()

if(EXISTS ${CMAKE_SOURCE_DIR}/Libraries/glfw3/CMakeLists.txt)
    add_subdirectory(Libraries/glfw3)
else()
    find_package(glfw3 REQUIRED)
endif()

if(EXISTS ${CMAKE_SOURCE_DIR}/Libraries/bullet3/CMakeLists.txt)
    add_subdirectory(Libraries/bullet3)
else()
    find_package(bullet3)
endif()

target_link_libraries(Vinegar ${LIBS})