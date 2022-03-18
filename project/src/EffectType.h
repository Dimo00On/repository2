#include <vector>
#include <string>
#pragma once

struct EffectType {
    float defenceInfluenceScale;
    float attackInfluenceScale;
    float hpInfluenceScale;
    int defenceInfluencePower;
    int attackInfluencePower;
    int hpInfluencePower;
    int cardAmountInfluence;
    int actionAmountInfluence;
    int time;
    bool isGood;
    bool isOnArea;
    std::string description;

    EffectType(const std::vector<float>& scaling, const std::vector<int>& power,
               const std::vector<bool>& params, const std::string& newDescription);
    EffectType() = default;
    EffectType(const EffectType& other) = default;
};