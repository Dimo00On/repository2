#include "AbstractFactory.h"

int AbstractFactory::cardAmount() {
    return static_cast<int>(allCards->size());
}

int AbstractFactory::enemyAmount() {
    return static_cast<int>(allEnemies->size());
}

void AbstractFactory::clearCard() {
    for (auto card : *allCards) {
        delete card;
    }
}

void AbstractFactory::clearEnemy() {
    for (auto enemy : *allEnemies) {
        delete enemy;
    }
}

AbstractFactory::~AbstractFactory() {
    clearCard();
    clearEnemy();
    delete allCards;
    delete allEnemies;
}

AbstractFactory::AbstractFactory() {
    allCards = new std::vector<Card*>;
    allEnemies = new std::vector<AbstractEnemy*>;
}