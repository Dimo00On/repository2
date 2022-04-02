#include <vector>
#include <string>
#pragma once

enum class OrderScale {Defence = 0, Damage, Hp};
enum class OrderPower {Defence = 0, Damage, Hp, CardAmount, ActionAmount, Time};
enum class OrderParams {Good = 0, OnArea};
class EffectType {
private:
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
    std::string* description;

public:
    EffectType(const std::vector<float>& scaling, const std::vector<int>& power,
               const std::vector<bool>& params, std::string* newDescription);
    EffectType() = default;
    EffectType(const EffectType& other) = default;
    void decreaseTime();
    int sayTime() const;
    float sayAttackScale() const;
    float sayDefenceScale() const;
    int sayAttackPower() const;
    int sayDefencePower() const;
    int sayActionAmount() const;
    int sayCardPerTurnAmount() const;
};

bool timeComp(const EffectType& first, const EffectType& second);