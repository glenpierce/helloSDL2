SET(SDL2_INCLUDE_DIR "C:/Users/glenp/code/SDL2-2.30.1/x86_64-w64-mingw32/include/SDL2")
SET(SDL2_LIBRARY     "C:/Users/glenp/code/SDL2-2.30.1/x86_64-w64-mingw32/lib/libSDL2.a")
#SET(SDL2MAIN_LIBRARY "C:/Users/glenp/code/SDL2-2.30.1/x86_64-w64-mingw32/lib")
INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2 REQUIRED_VARS SDL2_LIBRARY SDL2_INCLUDE_DIR)