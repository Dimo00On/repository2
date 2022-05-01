#include "GameProcess.h"
#include "../Enemy/WeakEnemy.h"
#include "../Enemy/CommonEnemy.h"
#include "../Enemy/StrongEnemy.h"
#include "InterfaceChooser.h"


extern bool timeToExit;

namespace Enemies{
    extern std::vector<AbstractEnemy*> allDeadEnemies;
}

GameProcess::GameProcess(Map& newMap, PlayerGameObject& newPlayer) : map(newMap), playerGameObject(newPlayer) {
    position = std::make_pair(0, 0);
}

void GameProcess::startChill() {
    int recover = std::min(kChillHpRecovery, kPlayerBaseHp - playerGameObject.sayHp());
    std::vector<int> temp(1);
    temp[0] = recover;
    playerGameObject.takeDamage(-recover);
    InterfaceChooser::write(kChosenInterface, "rest", &temp, nullptr);
}

Room* GameProcess::changeRoom(std::pair<int, int> direction) {
    position.first += direction.first;
    position.second += direction.second;
    return map.showMap()[position.first][position.second];
}

Room* GameProcess::changingPosition() {
    bool ok = false;
    std::pair<int, int> direction;
    while (!ok && !timeToExit) {
        InterfaceChooser::showMap(kChosenInterface, map, position);
        InterfaceChooser::showPaths(kChosenInterface, map, position);
        int answer = InterfaceChooser::read(kChosenInterface);
        if (answer == 0) {
            timeToExit = true;
            break;
        }
        if (answer == 1 && position.second > 0) {
            ok = true;
            direction.first = 0;
            direction.second = -1;
        }
        if (answer == 2 && position.second > 0) {
            ok = true;
            direction.first = 1;
            direction.second = -1;
        }
        if (answer == 3 && position.first + 1 < map.showMap().size()) {
            ok = true;
            direction.first = 1;
            direction.second = 0;
        }
        if (answer == 4 && position.first + 3 < map.showMap().size()) {
            ok = true;
            direction.first = 2;
            direction.second = 0;
        }
        if (answer == 5 && position.second + 1 < map.showMap()[position.first].size()) {
            ok = true;
            direction.first = 0;
            direction.second = 1;
        }
        if (answer == 6 && position.second + 1 < map.showMap()[position.first].size()) {
            ok = true;
            direction.first = 1;
            direction.second = 1;
        }
        if (!ok) {
            InterfaceChooser::write(kChosenInterface, "unknown", nullptr, nullptr);
        }
    }
    return changeRoom(direction);
}

void GameProcess::startCombat(AbstractEnemy* enemy) {
    bool win = false;
    std::deque<Card*> cardDeque;
    auto liveEnemy = dynamic_cast<LiveObject*>(enemy);
    {
        auto rng = std::default_random_engine{};
        cardDeque = playerGameObject.getDeque();
        std::shuffle(cardDeque.begin(), cardDeque.end(), rng);
    }
    int actionAmount;
    int cardPerTurnAmount;
    while (!win && !timeToExit) {
        if (playerGameObject.sayHp() <= 0) {
            InterfaceChooser::write(kChosenInterface, "dead", nullptr, nullptr);
            std::string command;
            std::cin >> command;
            timeToExit = true;
            break;
        }
        playerGameObject.effectsTimeDecrease();
        actionAmount = playerGameObject.sayActionAmount();
        cardPerTurnAmount = playerGameObject.sayCardPerTurnAmount();
        const std::vector<EffectType>& effects = playerGameObject.sayEffects();
        for (const auto & effect : effects) {
            actionAmount += effect.sayActionAmount();
            cardPerTurnAmount += effect.sayCardPerTurnAmount();
        }
        std::vector<Card*> hand;
        std::vector<bool> used(cardPerTurnAmount, false);
        for (int i = 0; i < cardPerTurnAmount; ++i) {
            if (cardDeque.empty()) {
                auto rng = std::default_random_engine {};
                cardDeque = playerGameObject.getDeque();
                std::shuffle(cardDeque.begin(), cardDeque.end(), rng);
            }
            hand.push_back(cardDeque.front());
            cardDeque.pop_front();
        }
        std::pair<int, int> damDef = enemy->nextAttack(playerGameObject);
        int newDefence = playerGameObject.sayDefence() / kDefenceDecreaseScalePerTurn;
        playerGameObject.takeDefence(newDefence - playerGameObject.sayDefence());
        while (actionAmount > 0 && !timeToExit && !win) {
            damDef = enemy->recalculate(playerGameObject);
            std::vector<int> tempValues(7);
            tempValues[0] = damDef.first;
            tempValues[1] = damDef.second;
            tempValues[2] = liveEnemy->sayHp();
            tempValues[3] = liveEnemy->sayDefence();
            tempValues[4] = actionAmount;
            tempValues[5] = playerGameObject.sayHp();
            tempValues[6] = playerGameObject.sayDefence();
            InterfaceChooser::showCombatStatus(kChosenInterface, tempValues);
            for (int i = 0; i < hand.size(); ++i) {
                if (!used[i]) {
                    std::pair<int, int> cardDamDef = hand[i]->realDamDef(&playerGameObject);
                    std::string description = hand[i]->sayDescription();
                    InterfaceChooser::showCard(kChosenInterface, i + 1, cardDamDef.first, cardDamDef.second, &description);
                }
            }
            bool ok = false;
            while (!ok) {
                int answer = InterfaceChooser::read(kChosenInterface);
                if (answer == 0) {
                    ok = true;
                    timeToExit = true;
                }
                if (answer > 0) {
                    for (int i = 0; i < hand.size(); ++i) {
                        if (answer == i + 1 && !used[answer - 1]) {
                            ok = true;
                            used[answer - 1] = true;
                            hand[i]->use(liveEnemy, &playerGameObject);
                        }
                        //hand.erase(hand.begin() + i);
                    }
                }
                if (!ok) {
                    InterfaceChooser::write(kChosenInterface, "unknown card", nullptr, nullptr);
                } else {
                    --actionAmount;
                }
            }
            if (liveEnemy->sayHp() <= 0) {
                win = true;
            }
        }
        if (!win) {
            liveEnemy->effectsTimeDecrease();
            newDefence = liveEnemy->sayDefence() / kDefenceDecreaseScalePerTurn;
            liveEnemy->takeDefence(newDefence - liveEnemy->sayDefence());
            enemy->attack(playerGameObject);
        }
    }
    if (win) {
        playerGameObject.clearEffects();
        playerGameObject.takeDefence(-playerGameObject.sayDefence());
        std::vector<int> tempValues(3);
        std::vector<std::string*> tempStrings(1);
        {
            auto tempEnemy = dynamic_cast<WeakEnemy*>(enemy);
            if (tempEnemy != nullptr) {
                tempValues[0] = 0;
                Card* reward = tempEnemy->getReward();
                std::pair<int, int> damDef = reward->realDamDef(&playerGameObject);
                std::string description = reward->sayDescription();
                tempValues[1] = damDef.first;
                tempValues[2] = damDef.second;
                tempStrings[0] = &description;
                playerGameObject.addReward(reward);
                tempEnemy->setReward(nullptr);
            }
        }
        {
            auto tempEnemy = dynamic_cast<CommonEnemy*>(enemy);
            if (tempEnemy != nullptr) {
                tempValues[0] = 1;
                Card* reward = tempEnemy->getReward();
                std::pair<int, int> damDef = reward->realDamDef(&playerGameObject);
                std::string description = reward->sayDescription();
                tempValues[1] = damDef.first;
                tempValues[2] = damDef.second;
                tempStrings[0] = &description;
                playerGameObject.addReward(reward);
                tempEnemy->setReward(nullptr);
            }
        }
        {
            auto tempEnemy = dynamic_cast<StrongEnemy*>(enemy);
            if (tempEnemy != nullptr) {
                tempValues[0] = 2;
                Artifact* reward = tempEnemy->getReward();
                playerGameObject.addReward(reward);
                tempEnemy->setReward(nullptr);
            }
        }
        InterfaceChooser::write(kChosenInterface, "kill", &tempValues, &tempStrings);
    }
    delete enemy;
}