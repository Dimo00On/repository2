#include <vector>
#include "../RoomFactory/ChillRoomFactory.h"
#include "../RoomFactory/CombatRoomFactory.h"
#include "../RoomFactory/EndRoomFactory.h"
#pragma once

class Map{
private:
    std::vector<std::vector<Room*>> rooms;

public:
    ~Map();
    void createNewMap(int size1, int size2);
    const std::vector<std::vector<Room*>>& showMap();
};