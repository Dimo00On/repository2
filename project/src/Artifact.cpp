#include "Artifact.h"

namespace Artifacts{
    std::vector<Artifact> allArtifacts;
}

void Artifact::doSomething() {
}

Artifact::Artifact(std::vector<bool>& params) {
    isCombatType = params[0];
    isPassive = params[1];
    isActive = params[2];
}