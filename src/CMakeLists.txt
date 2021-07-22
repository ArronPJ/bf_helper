cmake_minimum_required(VERSION 3.17)
project(bf_helper CXX)

#include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
#conan_basic_setup(TARGETS)

set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)

# STATIC?
add_library(bf_helper 
    bf_helper.cpp 
    bf_helper.h
    bf_object.cpp
    bf_object.h 
    bf_functions.cpp
    bf_functions.h 
)

#target_include_directories(bf_helper
#  PUBLIC
#    .
#  PRIVATE
#)

target_link_libraries(${PROJECT_NAME} PRIVATE CONAN_PKG::jansson CONAN_PKG::boost)
#org
#target_link_libraries(${PROJECT_NAME} CONAN_PKG::jansson)
#op1-fail
#target_link_libraries(${PROJECT_NAME} CONAN_PKG::jansson CONAN_PKG::boost::system)
#op2-ok
#target_link_libraries(${PROJECT_NAME} CONAN_PKG::jansson CONAN_PKG::boost)

#[[Need to add this for boost?
target_link_libraries(${PROJECT_NAME} CONAN_PKG::boost)
end?]]