#include "EffectType.h"
#pragma once

struct LiveObject {
    int hp;
    int defence;
    std::vector<EffectType> currentEffects;


    virtual ~LiveObject() = default;
    explicit LiveObject(int hpAmount);
};