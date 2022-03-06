cmake_minimum_required(VERSION 3.16)
project(NewLib)

set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../lib)
set(CMAKE_CXX_STANDARD 17)

add_library(NewLib SHARED ${CMAKE_CURRENT_SOURCE_DIR}/lib.h ${CMAKE_CURRENT_SOURCE_DIR}/lib.cpp)