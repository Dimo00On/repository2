#include "WeakFactory.h"
#include "CommonFactory.h"

WeakFactory* WeakFactory::factory = nullptr;

AbstractEnemy* WeakFactory::createEnemy(std::vector<AttackType>& attacks) {
    auto commonFactory = CommonFactory::getFactory();
    int chosenReward = rand() % commonFactory->cardAmount();
    auto reward = dynamic_cast<CommonCard*>(commonFactory->getCard(chosenReward));
    auto enemy = new WeakEnemy(attacks, reward);
    allEnemies->push_back(enemy);
    return enemy;
}

Card* WeakFactory::createCard(int damage, int defence, std::string* description,
                              std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs) {
    auto card = new WeakCard(defence, buffs, damage, debuffs, description);
    allCards->push_back(card);
    return card;
}

Card* WeakFactory::getCard(int index) {
    return new WeakCard(*dynamic_cast<WeakCard*>((*allCards)[index]));
}

AbstractEnemy* WeakFactory::getEnemy(int index) {
    auto enemy = new WeakEnemy(*dynamic_cast<WeakEnemy*>((*allEnemies)[index]));
    auto commonFactory = CommonFactory::getFactory();
    int chosenReward = rand() % commonFactory->cardAmount();
    auto reward = dynamic_cast<CommonCard*>(commonFactory->getCard(chosenReward));
    enemy->setReward(reward);
    return enemy;
}

WeakFactory::WeakFactory() : AbstractFactory() {}

WeakFactory* WeakFactory::getFactory() {
    if (factory == nullptr) {
        factory = new WeakFactory;
    }
    return factory;
}