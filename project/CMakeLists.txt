cmake_minimum_required(VERSION 3.16.3)
project(TheBestGameInTheWorld)

set(CMAKE_CXX_STANDARD 17)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(TheBestGameInTheWorld
        main.cpp
        src/Card.cpp
        src/Card.h
        src/EffectType.cpp
        src/EffectType.h
        src/LiveObject.cpp
        src/LiveObject.h
        src/Constants.h
        src/Enemy.cpp
        src/Enemy.h
        src/AttackType.cpp
        src/AttackType.h
        src/Artifact.cpp
        src/Artifact.h
        src/AbstractFactory.cpp
        src/AbstractFactory.h
        src/Room.cpp
        src/Room.h
        src/RoomFactory.cpp
        src/RoomFactory.h
        src/PlayerGameObject.cpp
        src/PlayerGameObject.h
        src/Map.cpp
        src/Map.h
        src/GameProcess.cpp
        src/GameProcess.h
        src/Client.cpp
        src/Client.h main.h)
