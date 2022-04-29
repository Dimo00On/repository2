#include "Card.h"
#pragma once

class WeakCard : public Card {
public:
    WeakCard() = default;
    WeakCard(const WeakCard& other) = default;
    WeakCard(int newShieldAmount, std::vector<EffectType>& newBuffs, int newDamage,
             std::vector<EffectType>& newDebuffs, const std::string* newDescription);
    void use(LiveObject* target, LiveObject* user) override;
    CardType sayCardType() override;
};