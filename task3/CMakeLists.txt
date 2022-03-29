cmake_minimum_required(VERSION 3.0)
project(SimpleLibrary)

include_directories(include)

#set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)
#set(CMAKE_CXX_COMPILER )

if (ARM_BUILD)
    set(CMAKE_SYSTEM_NAME Linux)
    set(CMAKE_SYSTEM_PROCESSOR arm)
    set(CMAKE_C_COMPILER ${TOOLCHAIN}/bin/arm-linux-gnueabihf-gcc)
    set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/bin/arm-linux-gnueabihf-g++)
endif()
add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

target_link_libraries(MainLib buffer)
install(TARGETS Main MainLib DESTINATION ${CMAKE_INSTALL_PREFIX})

