cmake_minimum_required(VERSION 3.0)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
SET(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-g++)
project(SimpleLibrary)

include_directories(include)

#SET(CMAKE_C_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-gcc)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)


#if (ARM_BUILD)
#    set(CMAKE_SYSTEM_NAME Linux)
#    set(CMAKE_SYSTEM_PROCESSOR aarch64)
#    set(CMAKE_C_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-gcc)
#    set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/aarch64-linux-gnu-c++)
#endif(ARM_BUILD)

add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

target_link_libraries(MainLib buffer)
install(TARGETS Main DESTINATION ${CMAKE_INSTALL_PREFIX})
install(TARGETS MainLib DESTINATION ${CMAKE_INSTALL_PREFIX})
