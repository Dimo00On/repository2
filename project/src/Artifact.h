#include <vector>
#pragma once

struct Artifact{
    bool isCombatType;
    bool isPassive;
    bool isActive;

    Artifact(std::vector<bool>& params);
    virtual void doSomething();
};
