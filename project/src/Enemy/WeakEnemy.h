#include "Enemy.h"
#include "../LiveObject/LiveObject.h"
#include "../Card/CommonCard.h"
#pragma once

class WeakEnemy : public AbstractEnemy, public LiveObject {
public:
    WeakEnemy();
    WeakEnemy(std::vector<AttackType>& newAttackTypes, Reward* newReward);
    WeakEnemy(const WeakEnemy& other) = default;
    ~WeakEnemy() override;
    void attack(LiveObject& object) override;
    std::pair<int, int> nextAttack(LiveObject& object) override;
    std::pair<int, int> recalculate(LiveObject& object) override;
    AbstractEnemy* clone() override;
};
