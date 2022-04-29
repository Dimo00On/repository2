#include "Artifact.h"
#include "ArtifactFactory.h"

void Artifact::setDescription(const std::string* newDescription) {
    description = newDescription;
}

Artifact::Artifact(std::vector<bool>& params) : Reward(RewardType::Artifact) {
    isCombatType = params[static_cast<int>(ArtifactParams::Combat)];
    isPassiveType = params[static_cast<int>(ArtifactParams::Passive)];
    isActiveType = params[static_cast<int>(ArtifactParams::Active)];
}

void createArtifacts() {
    auto factory = ArtifactFactory::getFactory();
    factory->createDamageArtifact();
}

bool Artifact::isCombat() {
    return isCombatType;
}

bool Artifact::isPassive() {
    return isPassiveType;
}

bool Artifact::isActive() {
    return isActiveType;
}

const std::string* Artifact::sayDescription() {
    return description;
}