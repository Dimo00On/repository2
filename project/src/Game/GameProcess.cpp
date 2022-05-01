#include "GameProcess.h"

extern bool timeToExit;

GameProcess::GameProcess(Map& newMap, PlayerGameObject& newPlayer, InterfaceChooser newInterface) :
        interface(newInterface), map(newMap), playerGameObject(newPlayer) {
    position = std::make_pair(0, 0);
}

void GameProcess::startChill() {
    int recover = std::min(kChillHpRecovery, kPlayerBaseHp - playerGameObject.sayHp());
    std::vector<int> temp(1);
    temp[0] = recover;
    playerGameObject.takeDamage(-recover);
    interface.write( "rest", &temp, nullptr);
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
        interface.showMap( map, position);
        interface.showPaths( map, position);
        int answer = interface.read();
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
            interface.write( "unknown", nullptr, nullptr);
        }
    }
    return changeRoom(direction);
}

void GameProcess::combatUpdatePlayer(int& actionAmount, int& cardPerTurnAmount,
                               std::vector<Card*>& hand, std::deque<Card*>& cardDeque) {
    playerGameObject.effectsTimeDecrease();
    actionAmount = playerGameObject.sayActionAmount();
    cardPerTurnAmount = playerGameObject.sayCardPerTurnAmount();
    const std::vector<EffectType>& effects = playerGameObject.sayEffects();
    for (const auto & effect : effects) {
        actionAmount += effect.sayActionAmount();
        cardPerTurnAmount += effect.sayCardPerTurnAmount();
    }
    for (int i = 0; i < cardPerTurnAmount; ++i) {
        if (cardDeque.empty()) {
            auto rng = std::default_random_engine {};
            cardDeque = playerGameObject.getDeque();
            std::shuffle(cardDeque.begin(), cardDeque.end(), rng);
        }
        hand.push_back(cardDeque.front());
        cardDeque.pop_front();
    }
    int newDefence = playerGameObject.sayDefence() / kDefenceDecreaseScalePerTurn;
    playerGameObject.takeDefence(newDefence - playerGameObject.sayDefence());
}

void GameProcess::combatUpdateEnemy(LiveObject* liveEnemy, AbstractEnemy* enemy) {
    liveEnemy->effectsTimeDecrease();
    int newDefence = liveEnemy->sayDefence() / kDefenceDecreaseScalePerTurn;
    liveEnemy->takeDefence(newDefence - liveEnemy->sayDefence());
    enemy->attack(playerGameObject);
}

void GameProcess::combatEnd(AbstractEnemy* enemy, std::vector<int>& tempValues,
                                std::vector<const std::string*>& tempStrings) {
    playerGameObject.clearEffects();
    playerGameObject.takeDefence(-playerGameObject.sayDefence());
    auto reward = enemy->getReward();
    enemy->setReward(nullptr);
    playerGameObject.addReward(reward);
    tempStrings[0] = reward->sayDescription();
    if (reward->sayType() == RewardType::Card) {
        auto card = reward->toCard();
        std::pair<int, int> damDef = card->realDamDef(&playerGameObject);
        tempValues[1] = damDef.first;
        tempValues[2] = damDef.second;
        tempValues[0] = static_cast<int>(card->sayCardType());
    } else {
        tempValues[0] = 3;
    }
}

void GameProcess::sendCombatStatus(AbstractEnemy* enemy, LiveObject* liveEnemy,
                                   int handSize, int& actionAmount, std::vector<Card*>& hand,
                                   std::vector<bool>& used, std::vector<bool>& usedArtifact) {
    std::pair<int, int> damDef = enemy->recalculate(playerGameObject);
    std::vector<int> tempValues(7);
    tempValues[0] = damDef.first;
    tempValues[1] = damDef.second;
    tempValues[2] = liveEnemy->sayHp();
    tempValues[3] = liveEnemy->sayDefence();
    tempValues[4] = actionAmount;
    tempValues[5] = playerGameObject.sayHp();
    tempValues[6] = playerGameObject.sayDefence();
    interface.showCombatStatus( tempValues,
                                       liveEnemy->getEffects(), playerGameObject.getEffects());
    for (int i = 0; i < handSize; ++i) {
        if (!used[i]) {
            std::pair<int, int> cardDamDef = hand[i]->realDamDef(&playerGameObject);
            const std::string* description = hand[i]->sayDescription();
            interface.showCard( i + 1, cardDamDef.first, cardDamDef.second, description);
        }
    }
    int counter = 0;
    for (auto& artifact : playerGameObject.getArtifacts()) {
        if (artifact->isCombat() && artifact->isActive() && !usedArtifact[counter]) {
            ++counter;
            interface.showArtifact(                     counter + handSize, artifact->sayDescription());
        }
    }
}

void GameProcess::playerDoCombatActions(int handSize, int& actionAmount, LiveObject* liveEnemy,
                                  std::vector<Card*>& hand, std::vector<bool>& used,
                                  std::vector<bool>& usedArtifact) {
    bool ok = false;
    while (!ok) {
        int answer = interface.read();
        if (answer == 0) {
            ok = true;
            timeToExit = true;
        }
        if (answer > 0) {
            for (int i = 0; i < handSize; ++i) {
                if (answer == i + 1 && !used[answer - 1]) {
                    ok = true;
                    used[answer - 1] = true;
                    hand[i]->use(liveEnemy, &playerGameObject);
                }
                //hand.erase(hand.begin() + i);
            }
            int counter = 0;
            for (auto& artifact : playerGameObject.getArtifacts()) {
                if (artifact->isCombat() && artifact->isActive()) {
                    ++counter;
                    if (answer == handSize + counter) {
                        ok = true;
                        usedArtifact[counter - 1] = true;
                        artifact->doSomething(&playerGameObject, liveEnemy);
                    }
                }
            }
        }
        if (!ok) {
            interface.write( "unknown card", nullptr, nullptr);
        } else {
            --actionAmount;
        }
    }
}

void GameProcess::startCombat(AbstractEnemy* enemy) {//TODO сделать класс состояние combat
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
    for (auto& artifact : playerGameObject.getArtifacts()) {
        if (artifact->isCombat() && artifact->isPassive()) {
            artifact->doSomething(&playerGameObject, liveEnemy);
        }
    }
    while (!win && !timeToExit) {
        if (playerGameObject.sayHp() <= 0) {
            interface.write( "dead", nullptr, nullptr);
            interface.read();
            timeToExit = true;
            break;
        }
        std::vector<Card*> hand;
        combatUpdatePlayer(actionAmount, cardPerTurnAmount, hand, cardDeque);
        std::vector<bool> used(cardPerTurnAmount, false);
        std::vector<bool> usedArtifact(playerGameObject.getArtifacts().size(), false);
        enemy->nextAttack(playerGameObject);
        while (actionAmount > 0 && !timeToExit && !win) {
            int handSize = static_cast<int>(hand.size());
            sendCombatStatus(enemy, liveEnemy, handSize, actionAmount, hand, used, usedArtifact);
            playerDoCombatActions(handSize, actionAmount, liveEnemy, hand, used, usedArtifact);
            if (liveEnemy->sayHp() <= 0) {
                win = true;
            }
        }
        if (!win) {
            combatUpdateEnemy(liveEnemy, enemy);
        }
    }
    if (win) {
        std::vector<int> tempValues(3);
        std::vector<const std::string*> tempStrings(1);
        combatEnd(enemy, tempValues, tempStrings);
        interface.write( "kill", &tempValues, &tempStrings);
    }
    delete enemy;
}