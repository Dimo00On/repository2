#include "AbstractFactory.h"
#include "../Enemy/StrongEnemy.h"
#include "../Card/StrongCard.h"
#pragma once

class StrongFactory : public AbstractFactory {
private:
    static StrongFactory* factory;

    StrongFactory();

public:
    StrongFactory(const StrongFactory& other) = delete;
    void operator=(const StrongFactory& other) = delete;
    static StrongFactory* getFactory();
    AbstractEnemy* createEnemy(std::vector<AttackType>& attacks) override;
    Card* createCard(int damage, int defence, const std::string* description,
                     std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs) override;
    AbstractEnemy* getEnemy(int index) override;
    Reward* getCard(int index) override;
};