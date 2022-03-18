#include "Room.h"
#pragma once

struct RoomFactory {
    virtual Room* create(int difficult) = 0;
};

struct EndRoomFactory : RoomFactory {
    Room* create(int difficult) override;
};

struct ChillRoomFactory : RoomFactory {
    Room* create(int difficult) override;
};

struct CombatRoomFactory : RoomFactory {
    Room* create(int difficult) override;
};
