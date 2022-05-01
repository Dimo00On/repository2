#include "Enemy.h"
#include "../Artifact/Artifact.h"
#pragma once

class StrongEnemy : public AbstractEnemy, public LiveObject {
public:
    StrongEnemy();
    StrongEnemy(std::vector<AttackType>& newAttackTypes, Reward* newReward);
    StrongEnemy(const StrongEnemy& other) = default;
    ~StrongEnemy() override;
    void attack(LiveObject& object) override;
    std::pair<int, int> nextAttack(LiveObject& object) override;
    std::pair<int, int> recalculate(LiveObject& object) override;
    AbstractEnemy* clone() override;
};