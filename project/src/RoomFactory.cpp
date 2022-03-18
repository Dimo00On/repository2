#include "RoomFactory.h"

Room* EndRoomFactory::create(int difficult) {
    auto endRoom = new EndRoom;
    return endRoom;
}

Room* ChillRoomFactory::create(int difficult) {
    auto chillRoom = new ChillRoom;
    return chillRoom;
}

Room* CombatRoomFactory::create(int difficult) {
    auto combatRoom = new CombatRoom;
    combatRoom->difficulty = difficult;
    return combatRoom;
}