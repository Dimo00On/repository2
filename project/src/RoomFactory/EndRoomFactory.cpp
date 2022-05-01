#include "EndRoomFactory.h"

Room* EndRoomFactory::create(Difficulty difficult) {
    auto endRoom = new EndRoom;
    return endRoom;
}