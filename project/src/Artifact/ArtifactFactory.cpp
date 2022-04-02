#include "ArtifactFactory.h"

ArtifactFactory* ArtifactFactory::factory = nullptr;

Artifact* ArtifactFactory::create(std::vector<bool> &params) {
    auto artifact =  new Artifact(params);
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
    return new Artifact(*(*allArtifacts)[index]);
}

int ArtifactFactory::artifactAmount() {
    return static_cast<int>(allArtifacts->size());
}