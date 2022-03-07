cmake_minimum_required(VERSION 3.16)
project(C)

find_package(GTest CONFIG REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

file(MAKE_DIRECTORY bin)
file(MAKE_DIRECTORY lib)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/B)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)
add_custom_command(
        OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/A/index.h
        COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/A/preparing.py ${CMAKE_CURRENT_SOURCE_DIR}/A/index.h
)
add_custom_target(indexGenerator DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/A/index.h)
add_executable(C ${CMAKE_CURRENT_SOURCE_DIR}/C/main.cpp)
add_dependencies(C indexGenerator)
target_include_directories(C PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/A)
target_include_directories(C PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/B)
target_include_directories(C PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_link_libraries(C PUBLIC NewLib)
add_executable(CTest ${CMAKE_CURRENT_SOURCE_DIR}/C/main_test.cpp ${CMAKE_CURRENT_SOURCE_DIR}/C/tests.cpp)
add_dependencies(CTest indexGenerator)
target_link_libraries(CTest PUBLIC GTest::gtest)
target_link_libraries(CTest PUBLIC NewLib)