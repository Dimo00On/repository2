#include "EndRoom.h"

RoomType EndRoom::sayType() {
    return RoomType::End;
}

bool EndRoom::sayIsEmpty() {
    return false;
}

void EndRoom::setEmpty(bool value) {}

void EndRoom::setDifficulty(Difficulty value) {}