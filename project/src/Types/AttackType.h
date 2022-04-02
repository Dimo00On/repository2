#include"EffectType.h"
#include "../LiveObject/LiveObject.h"
#pragma once

class AttackType{
private:
    int damage;
    int defence;
    std::vector<EffectType> buffs;
    std::vector<EffectType> debuffs;

public:
    AttackType(int newDamage, int newDefence, const std::vector<EffectType>& buffs,
               const std::vector<EffectType>& debuffs);
    AttackType() = default;
    std::pair<int, int> nextAttack(LiveObject& target, LiveObject& attacker);
    void makeAttack(LiveObject& target, LiveObject& attacker);
};
