#include "StrongFactory.h"
#include "../Artifact/ArtifactFactory.h"

StrongFactory* StrongFactory::factory = nullptr;

AbstractEnemy* StrongFactory::createEnemy(std::vector<AttackType>& attacks) {
    auto artifactFactory = ArtifactFactory::getFactory();
    int chosenReward = rand() % artifactFactory->artifactAmount();
    auto reward = artifactFactory->getArtifact(chosenReward);
    auto enemy = new StrongEnemy(attacks, reward);
    allEnemies->push_back(enemy);
    return enemy;
}

Card* StrongFactory::createCard(int damage, int defence, const std::string* description,
                              std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs) {
    auto card = new StrongCard(defence, buffs, damage, debuffs, description);
    allCards->push_back(card);
    return card;
}

Reward* StrongFactory::getCard(int index) {
    return ((*allCards)[index])->clone();
}

AbstractEnemy* StrongFactory::getEnemy(int index) {
    auto enemy = ((*allEnemies)[index])->clone();
    auto artifactFactory = ArtifactFactory::getFactory();
    int chosenReward = rand() % artifactFactory->artifactAmount();
    auto reward = artifactFactory->getArtifact(chosenReward);
    enemy->setReward(reward);
    return enemy;
}

StrongFactory::StrongFactory() : AbstractFactory() {}

StrongFactory* StrongFactory::getFactory() {
    if (factory == nullptr) {
        factory = new StrongFactory;
    }
    return factory;
}