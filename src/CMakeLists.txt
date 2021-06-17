cmake_minimum_required(VERSION 3.1)
project(bf_helper CXX)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_library(bf_helper bf_helper.cpp)

#[[Need to add this for boost?
target_link_libraries(${PROJECT_NAME} CONAN_PKG::boost)
end?]]