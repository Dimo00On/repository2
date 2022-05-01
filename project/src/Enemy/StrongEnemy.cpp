#include "StrongEnemy.h"
#include "../Const/Constants.h"

StrongEnemy::StrongEnemy() : LiveObject(kStrongHp) {}

StrongEnemy::StrongEnemy(std::vector<AttackType>& newAttackTypes, Reward* newReward) :
        LiveObject(kStrongHp), AbstractEnemy(newAttackTypes, newReward) {}

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

AbstractEnemy* StrongEnemy::clone() {
    return new StrongEnemy(*this);
}