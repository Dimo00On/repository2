#include "ChillRoom.h"

RoomType ChillRoom::sayType() {
    return RoomType::Chill;
}

bool ChillRoom::sayIsEmpty() {
    return isEmpty;
}

void ChillRoom::setEmpty(bool value) {
    isEmpty = value;
}

void ChillRoom::setDifficulty(Difficulty value) {}