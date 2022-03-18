#include"EffectType.h"
#include "LiveObject.h"
#pragma once

struct AttackType{
    int damage;
    int defence;
    std::vector<EffectType> buffs;
    std::vector<EffectType> debuffs;

    AttackType(int newDamage, int newDefence, const std::vector<EffectType>& buffs,
               const std::vector<EffectType>& debuffs);
    AttackType() = default;
    std::pair<int, int> nextAttack(LiveObject& target, LiveObject& attacker);
    void makeAttack(LiveObject& target, LiveObject& attacker);
};
