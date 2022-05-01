#include "../Room/Room.h"
#pragma once

class RoomFactory {
public:
    virtual Room* create(Difficulty difficult) = 0;
};
