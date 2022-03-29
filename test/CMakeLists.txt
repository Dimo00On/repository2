cmake_minimum_required(VERSION 3.0)
project(SimpleLibrary)

include_directories(include)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SimpleLibrary_SOURCE_DIR}/lib)
if (DARM_BUILD)
    set(CMAKE_CXX_COMPILER ${DTOOL_CHAIN}/aarch64-linux-gnu-gcc)
endif()
add_subdirectory(src)
add_executable(Main main.cpp)
add_executable(MainLib main_lib.cpp)

target_link_libraries(MainLib buffer)
install(TARGETS Main MainLib DESTINATION ${DCMAKE_INSTALL_PREFIX})
