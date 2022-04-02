#include "../LiveObject/LiveObject.h"
#include "../Types/AttackType.h"
#pragma once

class AbstractEnemy{
public:
    virtual ~AbstractEnemy() = default;
    virtual void attack(LiveObject& object) = 0;
    virtual std::pair<int, int> nextAttack(LiveObject& object) = 0;
    virtual std::pair<int, int> recalculate(LiveObject& object) = 0;
};
