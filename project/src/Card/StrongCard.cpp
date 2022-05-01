#include "StrongCard.h"

void StrongCard::use(LiveObject* target, LiveObject* user) {
    std::pair<int, int> damDef = realDamDef(user);
    target->takeDamage(damDef.first);
    user->takeDefence(damDef.second);
    user->takeEffects(buffs);
    target->takeEffects(debuffs);
}

StrongCard::StrongCard(int newShieldAmount, std::vector<EffectType>& newBuffs, int newDamage,
           std::vector<EffectType>& newDebuffs, const std::string* newDescription) :
           Card(newShieldAmount, newBuffs, newDamage, newDebuffs, newDescription) {}

CardType StrongCard::sayCardType() {
    return CardType::Strong;
}

Reward* StrongCard::clone() {
    return new StrongCard(*this);
}