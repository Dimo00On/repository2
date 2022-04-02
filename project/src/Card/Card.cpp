#include "Card.h"

Card::Card(int newShieldAmount, std::vector<EffectType>& newBuffs, int newDamage,
                   std::vector<EffectType>& newDebuffs, std::string *newDescription) :
        shieldAmount(newShieldAmount), buffs(newBuffs), damage(newDamage), debuffs(newDebuffs),
        description(newDescription) {}

std::pair<int, int> Card::realDamDef(LiveObject* user) {
    float realDamage = damage;
    float realDefence = shieldAmount;
    std::vector<EffectType> effects = user->sayEffects();
    for (int i = 0; i < effects.size(); ++i) {
        realDamage += effects[i].sayAttackPower();
        realDefence += effects[i].sayDefencePower();
    }
    for (int i = 0; i < effects.size(); ++i) {
        realDamage *= effects[i].sayAttackScale();
        realDefence *= effects[i].sayDefenceScale();
    }
    return std::make_pair<int, int>(realDamage, realDefence);
}

std::string& Card::sayDescription() {
    return *description;
}