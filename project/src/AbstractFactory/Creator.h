#include "AbstractFactory.h"
#pragma once

class Creator {
private:
    AbstractFactory* factory;

public:
    Creator() = default;
    ~Creator() {};
    void setFactory(AbstractFactory* newFactory);
    void createCard(int damage, int defence, const std::string* description,
                    std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs);
    void createEnemy(std::vector<AttackType>& attacks);
};