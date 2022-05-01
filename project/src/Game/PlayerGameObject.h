#include "../LiveObject/LiveObject.h"
#include "../Card/Card.h"
#include "../Artifact/Artifact.h"
#include "../Const/Constants.h"
#include <deque>
#pragma once

class GameProcess;

class PlayerGameObject : public LiveObject {
private:
    std::deque<Card*> cardDeque;
    std::vector<Artifact*> artifacts;
    int actionAmount = kBaseActionAmount;
    int cardPerTurnAmount = kBaseCardPerTurnAmount;

public:
    PlayerGameObject();
    ~PlayerGameObject();
    const std::deque<Card*>& getDeque();
    const std::vector<Artifact*>& getArtifacts();
    void setActionAmount(int value);
    void setCardPerTurn(int value);
    int sayActionAmount();
    int sayCardPerTurnAmount();
    void addReward(Card* newCard);
    void addReward(Artifact* newArtifact);
};