#include "Room.h"

int EndRoom::sayType() {
    return 0;
}

bool EndRoom::sayIsEmpty() {
    return false;
}

int ChillRoom::sayType() {
    return 1;
}

bool ChillRoom::sayIsEmpty() {
    return isEmpty;
}

int CombatRoom::sayType() {
    return 2;
}

bool CombatRoom::sayIsEmpty() {
    return isEmpty;
}