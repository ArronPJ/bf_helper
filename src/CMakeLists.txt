cmake_minimum_required(VERSION 3.1)
project(bf_helper CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(bf_helper bf_helper.cpp)
