#include "../Types/EffectType.h"
#pragma once

class AttackType;
class WeakCard;

class LiveObject {
protected:
    int hp;
    int defence;
    std::vector<EffectType> currentEffects;

public:
    virtual ~LiveObject() = default;
    explicit LiveObject(int hpAmount);
    LiveObject() = default;

    void takeDamage(int damage);
    void takeDefence(int shield);
    int sayDefence();
    int sayHp();
    const std::vector<EffectType>& sayEffects();
    void takeEffects(const std::vector<EffectType>& effects);
    void effectsTimeDecrease();
    void clearEffects();
};