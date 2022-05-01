#include "CommonFactory.h"
#include "StrongFactory.h"

CommonFactory* CommonFactory::factory = nullptr;

AbstractEnemy* CommonFactory::createEnemy(std::vector<AttackType>& attacks) {
    auto strongFactory = StrongFactory::getFactory();
    int chosenReward = rand() % strongFactory->cardAmount();
    auto reward = strongFactory->getCard(chosenReward);
    auto enemy = new CommonEnemy(attacks, reward);
    allEnemies->push_back(enemy);
    return enemy;
}

Card* CommonFactory::createCard(int damage, int defence, const std::string* description,
                              std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs) {
    auto card = new CommonCard(defence, buffs, damage, debuffs, description);
    allCards->push_back(card);
    return card;
}

Reward* CommonFactory::getCard(int index) {
    return ((*allCards)[index])->clone();
}

AbstractEnemy* CommonFactory::getEnemy(int index) {
    auto enemy = ((*allEnemies)[index])->clone();
    auto strongFactory = StrongFactory::getFactory();
    int chosenReward = rand() % strongFactory->cardAmount();
    auto reward = strongFactory->getCard(chosenReward);
    enemy->setReward(reward);
    return enemy;
}

CommonFactory* CommonFactory::getFactory() {
    if (factory == nullptr) {
        factory = new CommonFactory;
    }
    return factory;
}

CommonFactory::CommonFactory() : AbstractFactory() {}