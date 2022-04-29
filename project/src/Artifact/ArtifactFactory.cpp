#include "ArtifactFactory.h"
#include "DamageArtifact.h"
#include "../Const/Constants.h"

ArtifactFactory* ArtifactFactory::factory = nullptr;

Artifact* ArtifactFactory::createDamageArtifact() {
    std::vector<bool> params(3);
    params[static_cast<int>(ArtifactParams::Combat)] = true;
    params[static_cast<int>(ArtifactParams::Passive)] = true;
    params[static_cast<int>(ArtifactParams::Active)] = false;
    auto artifact = new DamageArtifact(params);
    artifact->setMultiplier(kBaseMultiplier);
    artifact->setDescription(&kDamageArtifactDescription);
    allArtifacts->push_back(artifact);
    return artifact;
}

Artifact* ArtifactFactory::create(std::vector<bool> &params) {
    auto artifact = new Artifact(params);
    allArtifacts->push_back(artifact);
    return artifact;
}

ArtifactFactory::ArtifactFactory() {
    allArtifacts = new std::vector<Artifact*>;
}

ArtifactFactory::~ArtifactFactory() {
    clear();
    delete allArtifacts;
}

ArtifactFactory* ArtifactFactory::getFactory() {
    if (factory == nullptr) {
        factory = new ArtifactFactory;
    }
    return factory;
}

void ArtifactFactory::clear() {
    for (auto artifact : *allArtifacts) {
        delete artifact;
    }
}

Artifact* ArtifactFactory::getArtifact(int index) {
    if ((*allArtifacts)[index]->sayArtifactType() == ArtifactType::DamageArtifact) {
        return new DamageArtifact(*dynamic_cast<DamageArtifact*>((*allArtifacts)[index]));
    }
    return new Artifact(*(*allArtifacts)[index]);
}

int ArtifactFactory::artifactAmount() {
    return static_cast<int>(allArtifacts->size());
}