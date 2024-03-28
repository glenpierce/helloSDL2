cmake_minimum_required(VERSION 3.27)
project(helloSDL2)

set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")

set(SDL2_PATH "C:/Users/glenp/code/SDL2-2.30.1-useful")
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

#set(SDL2_DLL_PATH "C:/Users/glenp/code/SDL2-2.30.1-useful/lib/x64/")
#
#file(GLOB SDL2_DLLS "${SDL2_DLL_PATH}/*.dll")
#
#foreach(SDL2_DLL IN LISTS SDL2_DLLS)
#    file(GET_RUNTIME_DEPENDENCIES
#            RESOLVED_DEPENDENCIES_VAR _
#            UNRESOLVED_DEPENDENCIES_VAR _
#            CONFLICTING_DEPENDENCIES_PREFIX _
#            EXECUTABLES ${SDL2_DLL}
##            DIRECTORIES "/path/to/additional/search/directories" # Add extra search directories if required
#    )
#
#    foreach(file ${_})
#        file(COPY ${file} DESTINATION "${CMAKE_BINARY_DIR}")
#    endforeach()
#endforeach()

add_executable(helloSDL2 main.cpp
        Line.cpp
        Line.h
        Shape.h
        Grid.cpp
        Grid.h
        Dot.cpp
        Dot.h
        Graph.cpp
        Graph.h
        Node.cpp
        Node.h)
target_link_libraries(helloSDL2 ${SDL2_LIBRARY})
