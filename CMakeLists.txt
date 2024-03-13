cmake_minimum_required(VERSION 3.27)
project(helloSDL2)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

set(SDL2_PATH "C:/Users/glenp/code/SDL2-2.30.1-useful")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

#set(IMM32_LIBRARY "C:/Windows/System32/imm32.dll")
#set(WINMM_LIBRARY "C:/Windows/System32/winmm.dll")

#find_library(IMM32_LIBRARY NAMES imm32)
#find_library(WINMM_LIBRARY NAMES winmm)

#if(NOT IMM32_LIBRARY)
#    message(FATAL_ERROR "IMM32 library not found")
#endif()
#
#if(NOT WINMM_LIBRARY)
#    message(FATAL_ERROR "WINMM library not found")
#endif()

add_executable(helloSDL2 main.cpp)
#target_link_libraries(helloSDL2 ${IMM32_LIBRARY} ${WINMM_LIBRARY} ${SDL2_LIBRARY})
target_link_libraries(helloSDL2 ${SDL2_LIBRARY})
