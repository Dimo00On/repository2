#include "AbstractFactory.h"
#include "../Enemy/WeakEnemy.h"
#include "../Card/WeakCard.h"
#pragma once

class WeakFactory : public AbstractFactory {
private:
    static WeakFactory* factory;

    WeakFactory();

public:
    WeakFactory(const WeakFactory& other) = delete;
    void operator=(const WeakFactory& other) = delete;
    static WeakFactory* getFactory();
    AbstractEnemy* createEnemy(std::vector<AttackType>& attacks) override;
    Card* createCard(int damage, int defence, const std::string* description,
                     std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs) override;
    AbstractEnemy* getEnemy(int index) override;
    Card* getCard(int index) override;
};