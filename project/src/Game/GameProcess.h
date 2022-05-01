#include "../Enemy/Enemy.h"
#include "PlayerGameObject.h"
#include "../Map/Map.h"
#include <iostream>
#include <algorithm>
#include <random>
#include "../Interface/InterfaceChooser.h"
#pragma once

class Client;

class GameProcess{
private:
    friend Client;
    InterfaceChooser interface;
    std::pair<int, int> position;
    Map& map;
    PlayerGameObject& playerGameObject;

public:
    GameProcess(Map& newMap, PlayerGameObject& newPlayer, InterfaceChooser newInterface);
    Room* changingPosition();
    void startCombat(AbstractEnemy* enemy);
    void startChill();

private://TODO сделать класс состояние combat
    void combatUpdatePlayer(int& actionAmount, int& cardPerTurnAmount,
                            std::vector<Card*>& hand, std::deque<Card*>& cardDeque);
    void combatUpdateEnemy(LiveObject* liveEnemy, AbstractEnemy* enemy);
    void combatEnd(AbstractEnemy* enemy, std::vector<int>& tempValues,
                   std::vector<const std::string*>& tempStrings);
    void sendCombatStatus(AbstractEnemy* enemy, LiveObject* liveEnemy,
                          int handSize, int& actionAmount, std::vector<Card*>& hand,
                          std::vector<bool>& used, std::vector<bool>& usedArtifact);
    void playerDoCombatActions(int handSize, int& actionAmount, LiveObject* liveEnemy,
                         std::vector<Card*>& hand, std::vector<bool>& used,
                         std::vector<bool>& usedArtifact);

private:
    Room* changeRoom(std::pair<int, int> direction);
};

bool timeComp(const EffectType& first, const EffectType& second);