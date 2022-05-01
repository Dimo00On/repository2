#include "Reward.h"

Reward::Reward(RewardType newType) : type(newType) {}

RewardType Reward::sayType() {
    return type;
}