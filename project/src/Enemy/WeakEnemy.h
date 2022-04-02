#include "Enemy.h"
#include "../LiveObject/LiveObject.h"
#include "../Card/CommonCard.h"
#pragma once

class WeakEnemy : public AbstractEnemy, public LiveObject {
private:
    std::vector<AttackType> attackTypes;
    CommonCard* reward;
    int chosenType;

public:
    WeakEnemy();
    WeakEnemy(std::vector<AttackType>& attackTypes, CommonCard* reward);
    WeakEnemy(const WeakEnemy& other) = default;
    ~WeakEnemy() override;
    void setReward(CommonCard* newReward);
    void attack(LiveObject& object) override;
    std::pair<int, int> nextAttack(LiveObject& object) override;
    std::pair<int, int> recalculate(LiveObject& object) override;
    Card* getReward();
};
