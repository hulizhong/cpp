cmake_minimum_required(VERSION 2.8)
project(cppLang)

set(CMAKE_BUILD_TYPE "debug")
# -std=c++11
set(CMAKE_CXX_FLAGS "-O0 -std=c++11")


############################################################ Add submodule director.
add_subdirectory(stl)

add_subdirectory(thread)


############################################################ ADD main compile file.
## Method1. add compile files one by one.
#LIST(APPEND HELLO_SERVER_SRC HelloServer.cpp)

SET(VPTR_SRC vptr.cpp)
add_executable(vptr ${VPTR_SRC})

SET(CLASS_SRC class.cpp)
add_executable(class ${CLASS_SRC})

