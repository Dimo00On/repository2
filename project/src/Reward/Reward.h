#include <string>
#pragma once

enum class RewardType{Card = 0, Artifact};
class Reward{
private:
    RewardType type;

public:
    Reward(RewardType newType);
    virtual ~Reward() = default;
    Reward(const Reward& other) = default;
    RewardType sayType();
    virtual const std::string* sayDescription() {return nullptr;};
};
