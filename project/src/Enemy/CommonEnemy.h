#include "Enemy.h"
#include "../Card/StrongCard.h"
#pragma once

class CommonEnemy : public AbstractEnemy, public LiveObject {
private:
    std::vector<AttackType> attackTypes;
    StrongCard* reward;
    int chosenType;

public:
    CommonEnemy();
    CommonEnemy(std::vector<AttackType>& newAttackTypes, StrongCard* newReward);
    CommonEnemy(const CommonEnemy& other) = default;
    ~CommonEnemy() override;
    void setReward(StrongCard* newReward);
    void attack(LiveObject& object) override;
    std::pair<int, int> nextAttack(LiveObject& object) override;
    std::pair<int, int> recalculate(LiveObject& object) override;
    Card* getReward();
};