#include <vector>
#pragma once

enum ArtifactParams {Combat = 0, Passive, Active};
class Artifact{
private:
    bool isCombatType;
    bool isPassive;
    bool isActive;

public:
    Artifact(std::vector<bool>& params);
    Artifact() = default;
    Artifact(const Artifact& other) = default;
    virtual void doSomething();
};

void createArtifacts();