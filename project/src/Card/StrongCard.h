#include "Card.h"
#pragma once

class StrongCard : public Card {
public:
    StrongCard() = default;
    StrongCard(const StrongCard& other) = default;
    StrongCard(int newShieldAmount, std::vector<EffectType>& newBuffs, int newDamage,
             std::vector<EffectType>& newDebuffs, const std::string* newDescription);
    void use(LiveObject* target, LiveObject* user) override;
    CardType sayCardType() override;
    Reward* clone() override;
};