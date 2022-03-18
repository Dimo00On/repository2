#include "Enemy.h"
#include "PlayerGameObject.h"
#include "Map.h"
#include <iostream>
#include <algorithm>
#include <random>
#pragma once

struct GameProcess{
    std::pair<int, int> position;
    Map& map;
    PlayerGameObject& playerGameObject;

    GameProcess(Map& newMap, PlayerGameObject& newPlayer);
    Room* changingPosition();
    void startCombat(AbstractEnemy* enemy);
    void startChill();

private:
    Room* changeRoom(std::pair<int, int> direction);
    void showMap();
};

bool timeComp(const EffectType& first, const EffectType& second);