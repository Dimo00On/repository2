#include "WeakCard.h"

void WeakCard::use(LiveObject* target, LiveObject* user) {
    std::pair<int, int> damDef = realDamDef(user);
    target->takeDamage(damDef.first);
    user->takeDefence(damDef.second);
    //user->takeEffects(buffs);
    //target->takeEffects(debuffs);
}

WeakCard::WeakCard(int newShieldAmount, std::vector<EffectType>& newBuffs, int newDamage,
                       std::vector<EffectType>& newDebuffs, const std::string* newDescription) :
        Card(newShieldAmount, newBuffs, newDamage, newDebuffs, newDescription) {}

CardType WeakCard::sayCardType() {
    return CardType::Weak;
}

Reward* WeakCard::clone() {
    return new WeakCard(*this);
}