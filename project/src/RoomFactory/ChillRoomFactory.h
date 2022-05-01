#include "RoomFactory.h"
#include "../Room/ChillRoom.h"
#pragma once

class ChillRoomFactory : public RoomFactory {
public:
    Room* create(Difficulty difficult) override;
};