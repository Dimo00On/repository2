#include "PlayerGameObject.h"
#include "../AbstractFactory/WeakFactory.h"

PlayerGameObject::PlayerGameObject() : LiveObject(kPlayerBaseHp) {
    auto factory = WeakFactory::getFactory();
    for (int i = 0; i < factory->cardAmount(); ++i) {
        for (int j = 0; j < kStartCardAmount; ++j) {
            cardDeque.push_back(factory->getCard(i));
        }
    }
}

const std::deque<Card*>& PlayerGameObject::getDeque() {
    return cardDeque;
}

const std::vector<Artifact*>&  PlayerGameObject::getArtifacts() {
    return artifacts;
}

void PlayerGameObject::setActionAmount(int value) {
    actionAmount = value;
}

void PlayerGameObject::setCardPerTurn(int value) {
    cardPerTurnAmount = value;
}

int PlayerGameObject::sayActionAmount() {
    return actionAmount;
}

int PlayerGameObject::sayCardPerTurnAmount() {
    return cardPerTurnAmount;
}

void PlayerGameObject::addReward(Reward* newReward) {
    RewardType type = newReward->sayType();
    if (type == RewardType::Card) {
        cardDeque.push_back(dynamic_cast<Card*>(newReward));
    }
    if (type == RewardType::Artifact) {
        artifacts.push_back(dynamic_cast<Artifact*>(newReward));
    }
}

PlayerGameObject::~PlayerGameObject() {
    for (auto card : cardDeque) {
        delete card;
    }
    /*for (auto artifact : artifacts) {
        delete artifact;
    }*/
}