#include "RoomFactory.h"
#include "../Room/EndRoom.h"
#pragma once

class EndRoomFactory : public RoomFactory {
public:
    Room* create(Difficulty difficult) override;
};