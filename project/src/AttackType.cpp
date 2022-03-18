#include "AttackType.h"

AttackType::AttackType(int newDamage, int newDefence, const std::vector<EffectType>& newBuffs,
           const std::vector<EffectType>& newDebuffs) : damage(newDamage), defence(newDefence),
           buffs(newBuffs), debuffs(newDebuffs) {
}

std::pair<int, int> AttackType::nextAttack(LiveObject& target, LiveObject& attacker) {
    float realDamage = damage;
    for (int i = 0; i < attacker.currentEffects.size(); ++i) {
        realDamage += attacker.currentEffects[i].attackInfluencePower;
    }
    for (int i = 0; i < attacker.currentEffects.size(); ++i) {
        realDamage *= attacker.currentEffects[i].attackInfluenceScale;
    }
    float realDefence = defence;
    for (int i = 0; i < attacker.currentEffects.size(); ++i) {
        realDefence += attacker.currentEffects[i].defenceInfluencePower;
    }
    for (int i = 0; i < attacker.currentEffects.size(); ++i) {
        realDefence *= attacker.currentEffects[i].defenceInfluenceScale;
    }
    return std::make_pair(static_cast<int>(realDamage), static_cast<int>(realDefence));
}

void AttackType::makeAttack(LiveObject& target, LiveObject& attacker) {
    std::pair<int, int> damDef = nextAttack(target, attacker);
    if (target.defence < damDef.first) {
        damDef.first -= target.defence;
        target.defence = 0;
        target.hp -= damDef.first;
    } else {
        target.defence -= damDef.first;
    }
    attacker.defence += damDef.second;
    for (int i = 0; i < debuffs.size(); ++i) {
        target.currentEffects.push_back(debuffs[i]);
    }
    for (int i = 0; i < buffs.size(); ++i) {
        attacker.currentEffects.push_back(buffs[i]);
    }
}