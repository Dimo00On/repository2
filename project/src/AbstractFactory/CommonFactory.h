#include "AbstractFactory.h"
#include "../Enemy/CommonEnemy.h"
#include "../Card/CommonCard.h"
#pragma once

class CommonFactory : public AbstractFactory {
private:
    static CommonFactory* factory;

    CommonFactory();

public:
    CommonFactory(const CommonFactory& other) = delete;
    void operator=(const CommonFactory& other) = delete;
    static CommonFactory* getFactory();
    AbstractEnemy* createEnemy(std::vector<AttackType>& attacks) override;
    Card* createCard(int damage, int defence, const std::string* description,
                     std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs) override;
    AbstractEnemy* getEnemy(int index) override;
    Card* getCard(int index) override;
};