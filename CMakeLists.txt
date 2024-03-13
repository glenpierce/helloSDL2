cmake_minimum_required(VERSION 3.27)
project(helloSDL2)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR})
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

set(SDL2_PATH "C:/Users/glenp/code/SDL2-2.30.1")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(helloSDL2 main.cpp)
target_link_libraries(helloSDL2 ${SDL2_LIBRARY})
