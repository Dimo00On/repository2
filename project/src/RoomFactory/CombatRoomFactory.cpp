#include "CombatRoomFactory.h"

Room* CombatRoomFactory::create(Difficulty difficult) {
    auto combatRoom = new CombatRoom;
    combatRoom->setDifficulty(difficult);
    return combatRoom;
}