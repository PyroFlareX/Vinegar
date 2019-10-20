cmake_minimum_required(VERSION 3.12.2)

PROJECT(Vinegar C CXX)

file(GLOB_RECURSE src RELATIVE ${CMAKE_SOURCE_DIR} "src/*.cpp")
file(GLOB_RECURSE src RELATIVE ${CMAKE_SOURCE_DIR} "Engine/*.cpp")

file(GLOB_RECURSE src RELATIVE ${CMAKE_SOURCE_DIR} "src/*.h")
file(GLOB_RECURSE src RELATIVE ${CMAKE_SOURCE_DIR} "Engine/*.h")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
add_executable(Vinegar ${src})

find_package(glfw3 CONFIG REQUIRED)
include_directories(${GLFW3_INCLUDE_DIRS})
set(LIBS ${LIBS} ${GLFW3_LIBRARIES})

find_package(glm CONFIG REQUIRED)
include_directories(${GLM_INCLUDE_DIRS})

find_package(glad CONFIG REQUIRED)
include_directories(${GLAD_INCLUDE_DIRS})
set(LIBS ${LIBS} ${GLAD_LIBRARIES})

target_link_libraries(Vinegar ${LIBS})