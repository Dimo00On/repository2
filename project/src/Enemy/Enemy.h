#include "../LiveObject/LiveObject.h"
#include "../Types/AttackType.h"
#include "../Reward/Reward.h"
#include <vector>
#pragma once

class AbstractEnemy{
protected:
    std::vector<AttackType> attackTypes;
    Reward* reward;
    int chosenType;

public:
    AbstractEnemy() = default;
    AbstractEnemy(std::vector<AttackType>& newAttackTypes, Reward* newReward);
    virtual ~AbstractEnemy() = default;
    virtual void attack(LiveObject& object) = 0;
    virtual std::pair<int, int> nextAttack(LiveObject& object) = 0;
    virtual std::pair<int, int> recalculate(LiveObject& object) = 0;
    Reward* getReward();
    void setReward(Reward* newReward);
};

void createEnemies();