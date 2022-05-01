#include "Enemy.h"
#include "../AbstractFactory/WeakFactory.h"
#include "../AbstractFactory/CommonFactory.h"
#include "../AbstractFactory/StrongFactory.h"
#include "../AbstractFactory/Creator.h"

void createEnemies() {
    Creator creator;
    creator.setFactory(WeakFactory::getFactory());
    std::vector<EffectType> empty;
    std::vector<AttackType> attacks;
    {
        AttackType attack1(10, 0, empty, empty);
        AttackType attack2(0, 10, empty, empty);
        AttackType attack3(7, 6, empty, empty);
        attacks.push_back(attack1);
        attacks.push_back(attack1);
        attacks.push_back(attack2);
        attacks.push_back(attack2);
        attacks.push_back(attack3);
    }
    creator.createEnemy(attacks);
    attacks.clear();
    creator.setFactory(CommonFactory::getFactory());
    {
        AttackType attack1(15, 5, empty, empty);
        AttackType attack2(8, 12, empty, empty);
        AttackType attack3(30, 0, empty, empty);
        attacks.push_back(attack1);
        attacks.push_back(attack1);
        attacks.push_back(attack2);
        attacks.push_back(attack2);
        attacks.push_back(attack3);
    }
    creator.createEnemy(attacks);
    attacks.clear();
    creator.setFactory(StrongFactory::getFactory());
    {
        AttackType attack1(20, 10, empty, empty);
        AttackType attack2(10, 20, empty, empty);
        AttackType attack3(40, 0, empty, empty);
        AttackType attack4(0, 50, empty, empty);
        attacks.push_back(attack1);
        attacks.push_back(attack1);
        attacks.push_back(attack2);
        attacks.push_back(attack2);
        attacks.push_back(attack3);
        attacks.push_back(attack4);
    }
    creator.createEnemy(attacks);
    attacks.clear();
}

AbstractEnemy::AbstractEnemy(std::vector<AttackType>& newAttackTypes, Reward* newReward) :
    attackTypes(newAttackTypes), reward(newReward) {};

void AbstractEnemy::setReward(Reward* newReward) {
    reward = newReward;
}

Reward* AbstractEnemy::getReward() {
    return reward;
}