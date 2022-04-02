#include <vector>
#include "../RoomFactory/ChillRoomFactory.h"
#include "../RoomFactory/CombatRoomFactory.h"
#include "../RoomFactory/EndRoomFactory.h"
#pragma once

class GameProcess;
class Client;
class Map{
private:
    friend GameProcess;
    friend Client;
    std::vector<std::vector<Room*>> rooms;

public:
    ~Map();
    void createNewMap(int size1, int size2);
};