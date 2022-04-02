#include "../Enemy/Enemy.h"
#include "PlayerGameObject.h"
#include "../Map/Map.h"
#include <iostream>
#include <algorithm>
#include <random>
#pragma once

class GameProcess{
private:
    friend Client;
    std::pair<int, int> position;
    Map& map;
    PlayerGameObject& playerGameObject;

public:
    GameProcess(Map& newMap, PlayerGameObject& newPlayer);
    Room* changingPosition();
    void startCombat(AbstractEnemy* enemy);
    void startChill();

private:
    Room* changeRoom(std::pair<int, int> direction);
    void showMap();
};

bool timeComp(const EffectType& first, const EffectType& second);