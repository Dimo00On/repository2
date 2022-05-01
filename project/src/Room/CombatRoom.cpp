#include "CombatRoom.h"

RoomType CombatRoom::sayType() {
    return RoomType::Combat;
}

bool CombatRoom::sayIsEmpty() {
    return isEmpty;
}

void CombatRoom::setEmpty(bool value) {
    isEmpty = value;
}

void CombatRoom::setDifficulty(Difficulty value) {
    difficulty = value;
}

Difficulty CombatRoom::sayDifficulty() {
    return difficulty;
}