#include "Enemy.h"
#include "../Card/StrongCard.h"
#pragma once

class CommonEnemy : public AbstractEnemy, public LiveObject {
public:
    CommonEnemy();
    CommonEnemy(std::vector<AttackType>& newAttackTypes, Reward* newReward);
    CommonEnemy(const CommonEnemy& other) = default;
    ~CommonEnemy() override;
    void attack(LiveObject& object) override;
    std::pair<int, int> nextAttack(LiveObject& object) override;
    std::pair<int, int> recalculate(LiveObject& object) override;
};