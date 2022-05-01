#include "WeakEnemy.h"
#include "../Const/Constants.h"

WeakEnemy::WeakEnemy() : LiveObject(kWeakHp) {}

WeakEnemy::WeakEnemy(std::vector<AttackType>& newAttackTypes, Reward* newReward) :
LiveObject(kWeakHp), AbstractEnemy(newAttackTypes, newReward) {}

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

AbstractEnemy* WeakEnemy::clone() {
    return new WeakEnemy(*this);
}