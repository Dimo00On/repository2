#include "LiveObject.h"
#include "Card.h"
#include "Artifact.h"
#include "Constants.h"
#include <deque>
#pragma once

struct PlayerGameObject : LiveObject {
    std::deque<Card*> cardDeque;
    std::vector<Artifact*> artifacts;
    int actionAmount = kBaseActionAmount;
    int cardPerTurnAmount = kBaseCardPerTurnAmount;

    PlayerGameObject();
};