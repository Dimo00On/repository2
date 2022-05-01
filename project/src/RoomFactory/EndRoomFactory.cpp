#include "EndRoomFactory.h"

Room* EndRoomFactory::create(Difficulty difficult) {
    return new EndRoom;
}