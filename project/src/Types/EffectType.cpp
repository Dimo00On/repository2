#include "EffectType.h"

bool timeComp(const EffectType& first, const EffectType& second) {
    return first.sayTime() > second.sayTime();
}

EffectType::EffectType(const std::vector<float>& scaling, const std::vector<int>& power,
                       const std::vector<bool>& params, std::string* newDescription) {
    defenceInfluenceScale = scaling[static_cast<int>(OrderScale::Defence)];
    attackInfluenceScale = scaling[static_cast<int>(OrderScale::Damage)];
    hpInfluenceScale = scaling[static_cast<int>(OrderScale::Hp)];
    defenceInfluencePower = power[static_cast<int>(OrderPower::Defence)];
    attackInfluencePower = power[static_cast<int>(OrderPower::Damage)];
    hpInfluencePower = power[static_cast<int>(OrderPower::Hp)];
    cardAmountInfluence = power[static_cast<int>(OrderPower::CardAmount)];
    actionAmountInfluence = power[static_cast<int>(OrderPower::ActionAmount)];
    time = power[static_cast<int>(OrderPower::Time)];
    isGood = params[static_cast<int>(OrderParams::Good)];
    isOnArea = params[static_cast<int>(OrderParams::OnArea)];
    description = newDescription;
}

void EffectType::decreaseTime() {
    --time;
}

int EffectType::sayTime() const {
    return time;
}

int EffectType::sayAttackPower() const {
    return attackInfluencePower;
}

float EffectType::sayAttackScale() const {
    return attackInfluenceScale;
}

int EffectType::sayDefencePower() const {
    return defenceInfluencePower;
}

float EffectType::sayDefenceScale() const {
    return defenceInfluenceScale;
}

int EffectType::sayActionAmount() const {
    return actionAmountInfluence;
}

int EffectType::sayCardPerTurnAmount() const {
    return cardAmountInfluence;
}
