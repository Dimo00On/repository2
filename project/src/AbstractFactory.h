#include "Enemy.h"
#include "Card.h"
#include "Constants.h"
#pragma once

struct AbstractFactory {
    virtual AbstractEnemy* createEnemy(std::vector<AttackType>& attacks) = 0;
    virtual Card* createCard(int damage, int defence, std::string* description,
                            std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs) = 0;
};

struct WeakFactory : AbstractFactory {
    AbstractEnemy* createEnemy(std::vector<AttackType>& attacks) override;
    Card* createCard(int damage, int defence, std::string* description,
                     std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs) override;
};

struct CommonFactory : AbstractFactory {
    AbstractEnemy* createEnemy(std::vector<AttackType>& attacks) override;
    Card* createCard(int damage, int defence, std::string* description,
                     std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs) override;
};

struct StrongFactory : AbstractFactory {
    AbstractEnemy* createEnemy(std::vector<AttackType>& attacks) override;
    Card* createCard(int damage, int defence, std::string* description,
                     std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs) override;
};