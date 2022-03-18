#include "Enemy.h"
#include "Constants.h"

namespace Enemies{
    std::vector<AbstractEnemy*> allEnemies;
    std::vector<WeakEnemy*> allWeakEnemies;
    std::vector<CommonEnemy*> allCommonEnemies;
    std::vector<StrongEnemy*> allStrongEnemies;
    std::vector<AbstractEnemy*> allDeadEnemies;
}

WeakEnemy::WeakEnemy() : LiveObject(kWeakHp) {}

void WeakEnemy::attack(LiveObject& object) {
    attackTypes[chosenType].makeAttack(object, *this);
}

std::pair<int, int> WeakEnemy::nextAttack(LiveObject& object) {
    chosenType = static_cast<int>(rand()) % static_cast<int>(attackTypes.size());
    return attackTypes[chosenType].nextAttack(object, *this);
}

WeakEnemy::~WeakEnemy() {
    delete reward;
}

std::pair<int, int> WeakEnemy::recalculate(LiveObject& object) {
    return attackTypes[chosenType].nextAttack(object, *this);
}

CommonEnemy::CommonEnemy() : LiveObject(kCommonHp) {}

void CommonEnemy::attack(LiveObject& object) {
    attackTypes[chosenType].makeAttack(object, *this);
}

std::pair<int, int> CommonEnemy::nextAttack(LiveObject& object) {
    chosenType = static_cast<int>(rand()) % static_cast<int>(attackTypes.size());
    return attackTypes[chosenType].nextAttack(object, *this);
}

CommonEnemy::~CommonEnemy() {
    delete reward;
}

std::pair<int, int> CommonEnemy::recalculate(LiveObject& object) {
    return attackTypes[chosenType].nextAttack(object, *this);
}

StrongEnemy::StrongEnemy() : LiveObject(kStrongHp) {};

void StrongEnemy::attack(LiveObject& object) {
    attackTypes[chosenType].makeAttack(object, *this);
}

std::pair<int, int> StrongEnemy::nextAttack(LiveObject& object) {
    chosenType = static_cast<int>(rand()) % static_cast<int>(attackTypes.size());
    return attackTypes[chosenType].nextAttack(object, *this);
}

StrongEnemy::~StrongEnemy() {
    delete reward;
}

std::pair<int, int> StrongEnemy::recalculate(LiveObject& object) {
    return attackTypes[chosenType].nextAttack(object, *this);
}
