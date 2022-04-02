#include "Artifact.h"

void Artifact::doSomething() {
}

Artifact::Artifact(std::vector<bool>& params) {
    isCombatType = params[static_cast<int>(ArtifactParams::Combat)];
    isPassive = params[static_cast<int>(ArtifactParams::Passive)];
    isActive = params[static_cast<int>(ArtifactParams::Active)];
}