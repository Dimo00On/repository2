cmake_minimum_required(VERSION 3.16.3)
project(TheBestGameInTheWorld)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

add_subdirectory(src/AbstractFactory)
add_subdirectory(src/Artifact)
add_subdirectory(src/Card)
add_subdirectory(src/Enemy)
add_subdirectory(src/Game)
add_subdirectory(src/LiveObject)
add_subdirectory(src/Map)
add_subdirectory(src/Room)
add_subdirectory(src/RoomFactory)
add_subdirectory(src/Types)
add_executable(TheBestGameInTheWorld
        main.cpp
        main.h
        src/Const/Constants.h)
target_link_libraries(TheBestGameInTheWorld
        AbstractFactory
        Artifact
        Card
        Enemy
        Game
        LiveObject
        Map
        Room
        RoomFactory
        Types)
