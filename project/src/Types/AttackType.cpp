#include "AttackType.h"

AttackType::AttackType(int newDamage, int newDefence, const std::vector<EffectType>& newBuffs,
           const std::vector<EffectType>& newDebuffs) : damage(newDamage), defence(newDefence),
           buffs(newBuffs), debuffs(newDebuffs) {
}

std::pair<int, int> AttackType::nextAttack(LiveObject& target, LiveObject& attacker) {
    float realDamage = damage;
    const std::vector<EffectType>& effects = attacker.sayEffects();
    for (auto & currentEffect : effects) {
        realDamage += currentEffect.sayAttackPower();
    }
    for (auto & currentEffect : effects) {
        realDamage *= currentEffect.sayAttackScale();
    }
    float realDefence = defence;
    for (auto & currentEffect : effects) {
        realDefence += currentEffect.sayDefencePower();
    }
    for (auto & currentEffect : effects) {
        realDefence *= currentEffect.sayDefenceScale();
    }
    return std::make_pair(static_cast<int>(realDamage), static_cast<int>(realDefence));
}

void AttackType::makeAttack(LiveObject& target, LiveObject& attacker) {
    std::pair<int, int> damDef = nextAttack(target, attacker);
    target.takeDamage(damDef.first);
    attacker.takeDefence(damDef.second);
    target.takeEffects(debuffs);
    attacker.takeEffects(buffs);
}