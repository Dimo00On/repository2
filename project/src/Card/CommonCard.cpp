#include "CommonCard.h"

void CommonCard::use(LiveObject* target, LiveObject* user) {
    std::pair<int, int> damDef = realDamDef(user);
    target->takeDamage(damDef.first);
    user->takeDefence(damDef.second);
    user->takeEffects(buffs);
    //target->takeEffects(debuffs);
}

CommonCard::CommonCard(int newShieldAmount, std::vector<EffectType>& newBuffs, int newDamage,
                       std::vector<EffectType>& newDebuffs, const std::string* newDescription) :
        Card(newShieldAmount, newBuffs, newDamage, newDebuffs, newDescription) {}

CardType CommonCard::sayCardType() {
    return CardType::Common;
}