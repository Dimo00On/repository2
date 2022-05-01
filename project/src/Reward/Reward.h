#include <string>
#pragma once

enum class RewardType{Card = 0, Artifact};
class Card;
class Artifact;
class Reward{
private:
    RewardType type;

public:
    Reward(RewardType newType);
    virtual ~Reward() = default;
    Reward(const Reward& other) = default;
    RewardType sayType();
    virtual const std::string* sayDescription() = 0;
    virtual Card* toCard() {return nullptr;};
    virtual Artifact* toArtifact() {return nullptr;};
    virtual Reward* clone() = 0;
};