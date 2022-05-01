#include "Card.h"
#pragma once

class CommonCard : public Card {
public:
    CommonCard() = default;
    CommonCard(const CommonCard& other) = default;
    CommonCard(int newShieldAmount, std::vector<EffectType>& newBuffs, int newDamage,
             std::vector<EffectType>& newDebuffs, std::string* newDescription);
    void use(LiveObject* target, LiveObject* user) override;
};
