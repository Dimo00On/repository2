#include "CommonEnemy.h"
#include "../Const/Constants.h"

CommonEnemy::CommonEnemy() : LiveObject(kCommonHp) {}

CommonEnemy::CommonEnemy(std::vector<AttackType>& newAttackTypes, Reward* newReward) :
        LiveObject(kCommonHp), AbstractEnemy(newAttackTypes, newReward) {}

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
