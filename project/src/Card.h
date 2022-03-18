#include "EffectType.h"
#include "LiveObject.h"
#pragma once

struct Card{
    virtual void use(LiveObject* target, LiveObject* user) = 0;
    virtual std::string& sayDescription() = 0;
    virtual std::pair<int, int> realDamDef(LiveObject* user) = 0;
};

struct WeakCard : Card {
    int shieldAmount;
    std::vector<EffectType> buffs;
    int damage;
    std::vector<EffectType> debuffs;
    std::string* description;
    
    void use(LiveObject* target, LiveObject* user) override;
    std::string& sayDescription() override;
    std::pair<int, int> realDamDef(LiveObject* user) override;
};

struct CommonCard : Card {
    int shieldAmount;
    std::vector<EffectType> buffs;
    int damage;
    std::vector<EffectType> debuffs;
    std::string* description;

    void use(LiveObject* target, LiveObject* user) override;
    std::string& sayDescription() override;
    std::pair<int, int> realDamDef(LiveObject* user) override;
};

struct StrongCard : Card {
    int shieldAmount;
    std::vector<EffectType> buffs;
    int damage;
    std::vector<EffectType> debuffs;
    std::string* description;

    void use(LiveObject* target, LiveObject* user) override;
    std::string& sayDescription() override;
    std::pair<int, int> realDamDef(LiveObject* user) override;
};
