#include "Enemy.h"
#include "../Artifact/Artifact.h"
#pragma once

class StrongEnemy : public AbstractEnemy, public LiveObject {
private:
    std::vector<AttackType> attackTypes;
    Artifact* reward;
    int chosenType;

public:
    StrongEnemy();
    StrongEnemy(std::vector<AttackType>& attackTypes, Artifact* reward);
    StrongEnemy(const StrongEnemy& other) = default;
    ~StrongEnemy() override;
    void setReward(Artifact* newReward);
    void attack(LiveObject& object) override;
    std::pair<int, int> nextAttack(LiveObject& object) override;
    std::pair<int, int> recalculate(LiveObject& object) override;
    Artifact* getReward();
};