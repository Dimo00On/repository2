#include "LiveObject.h"
#include <algorithm>

LiveObject::LiveObject(int hpAmount) : hp(hpAmount), defence(0) {}

void LiveObject::takeDamage(int damage) {
    if (defence < damage) {
        damage -= defence;
        defence = 0;
        hp -= damage;
    } else {
        defence -= damage;
    }
}

void LiveObject::takeDefence(int shield) {
    defence += shield;
}

void LiveObject::takeEffects(const std::vector<EffectType>& effects) {
    for (auto & effect : effects) {
        currentEffects.push_back(effect);
    }
}

int LiveObject::sayDefence() {
    return defence;
}

int LiveObject::sayHp() {
    return hp;
}

const std::vector<EffectType> &LiveObject::sayEffects() {
    return currentEffects;
}

void LiveObject::effectsTimeDecrease() {
    for (auto & currentEffect : currentEffects) {
        currentEffect.decreaseTime();
    }
    std::sort(currentEffects.begin(), currentEffects.end(), timeComp);
    for (int i = static_cast<int>(currentEffects.size()) - 1; i >= 0; --i) {
        if (currentEffects[i].sayTime() > 0) {
            break;
        }
        currentEffects.pop_back();
    }
}

void LiveObject::clearEffects() {
    currentEffects.clear();
}
