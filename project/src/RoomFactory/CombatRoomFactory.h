#include "RoomFactory.h"
#include "../Room/CombatRoom.h"
#pragma once

class CombatRoomFactory : public RoomFactory {
public:
    Room* create(Difficulty difficult) override;
};
