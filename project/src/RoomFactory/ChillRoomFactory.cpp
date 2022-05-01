#include "ChillRoomFactory.h"

Room* ChillRoomFactory::create(Difficulty difficult) {
    auto chillRoom = new ChillRoom;
    return chillRoom;
}