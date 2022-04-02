#include "../Types/EffectType.h"
#include "../LiveObject/LiveObject.h"
#pragma once

class Card{
protected:
    int shieldAmount;
    std::vector<EffectType> buffs;
    int damage;
    std::vector<EffectType> debuffs;
    std::string* description;

public:
    Card(int newShieldAmount, std::vector<EffectType>& newBuffs, int newDamage,
         std::vector<EffectType>& newDebuffs, std::string *newDescription);
    Card() = default;

    virtual void use(LiveObject* target, LiveObject* user) = 0;
    virtual std::string& sayDescription();
    std::pair<int, int> realDamDef(LiveObject* user);
    virtual ~Card() = default;
};

void createCards();