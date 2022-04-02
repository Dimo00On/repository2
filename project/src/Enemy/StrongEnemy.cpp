#include "StrongEnemy.h"
#include "../Const/Constants.h"

StrongEnemy::StrongEnemy() : LiveObject(kStrongHp) {}

StrongEnemy::StrongEnemy(std::vector<AttackType>& newAttackTypes, Artifact* newReward) :
        LiveObject(kStrongHp), attackTypes(newAttackTypes), reward(newReward) {}

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

void StrongEnemy::setReward(Artifact* newReward) {
    reward = newReward;
}

Artifact* StrongEnemy::getReward() {
    return reward;
}