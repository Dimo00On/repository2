#include "Artifact.h"
#include "ArtifactFactory.h"

void Artifact::doSomething() {
}

Artifact::Artifact(std::vector<bool>& params) {
    isCombatType = params[static_cast<int>(ArtifactParams::Combat)];
    isPassive = params[static_cast<int>(ArtifactParams::Passive)];
    isActive = params[static_cast<int>(ArtifactParams::Active)];
}

void createArtifacts() {
    std::vector<bool> forArtifact(3, false);
    auto factory = ArtifactFactory::getFactory();
    factory->create(forArtifact);
}