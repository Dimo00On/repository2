#include <vector>
#include <cstdlib>
#include "Room.h"
#include "RoomFactory.h"
#include "Constants.h"
#pragma once

struct Map{
    std::vector<std::vector<Room*>> rooms;

    ~Map();
    void createNewMap(int size1, int size2);
};