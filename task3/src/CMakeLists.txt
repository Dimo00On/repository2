add_library(buffer SHARED buffer.cpp)
set_target_properties(buffer PROPERTIES PUBLIC_HEADER ../include/buffer.h)
INSTALL(TARGETS buffer
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_PREFIX}/include
        )