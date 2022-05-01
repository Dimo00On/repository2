#include "../Enemy/Enemy.h"
#include "../Card/Card.h"
#include "../Const/Constants.h"
#pragma once

class EnemyData;
class AbstractFactory {
protected:
    std::vector<AbstractEnemy*>* allEnemies = nullptr;
    std::vector<Card*>* allCards = nullptr;

    AbstractFactory();

public:
    virtual ~AbstractFactory();
    virtual AbstractEnemy* createEnemy(std::vector<AttackType>& attacks) = 0;
    virtual Card* createCard(int damage, int defence, std::string* description,
                            std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs) = 0;
    virtual AbstractEnemy* getEnemy(int index) = 0;
    virtual Card* getCard(int index) = 0;
    int cardAmount();
    int enemyAmount();
    void clearCard();
    void clearEnemy();
};