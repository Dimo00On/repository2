#include "ChillRoomFactory.h"

Room* ChillRoomFactory::create(Difficulty difficult) {
    return new ChillRoom;
}