#include "LiveObject.h"
#include "Card.h"
#include "AttackType.h"
#include "Artifact.h"
#pragma once

struct AbstractEnemy{
    virtual void attack(LiveObject& object) = 0;
    virtual std::pair<int, int> nextAttack(LiveObject& object) = 0;
    virtual ~AbstractEnemy() = default;
    virtual std::pair<int, int> recalculate(LiveObject& object) = 0;
};

struct WeakEnemy : AbstractEnemy, LiveObject {
    std::vector<AttackType> attackTypes;
    CommonCard* reward;
    int chosenType;

    WeakEnemy();
    void attack(LiveObject& object) override;
    std::pair<int, int> nextAttack(LiveObject& object) override;
    ~WeakEnemy() override;
    std::pair<int, int> recalculate(LiveObject& object) override;
};

struct CommonEnemy : AbstractEnemy, LiveObject {
    std::vector<AttackType> attackTypes;
    StrongCard* reward;
    int chosenType;

    CommonEnemy();
    void attack(LiveObject& object) override;
    std::pair<int, int> nextAttack(LiveObject& object) override;
    ~CommonEnemy() override;
    std::pair<int, int> recalculate(LiveObject& object) override;
};

struct StrongEnemy : AbstractEnemy, LiveObject {
    std::vector<AttackType> attackTypes;
    Artifact* reward;
    int chosenType;

    StrongEnemy();
    void attack(LiveObject& object) override;
    std::pair<int, int> nextAttack(LiveObject& object) override;
    ~StrongEnemy() override;
    std::pair<int, int> recalculate(LiveObject& object) override;
};
