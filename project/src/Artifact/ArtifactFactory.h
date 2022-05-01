#include "Artifact.h"

class ArtifactFactory {
private:
    std::vector<Artifact*>* allArtifacts = nullptr;
    static ArtifactFactory* factory;

    ArtifactFactory();

public:
    ~ArtifactFactory();
    ArtifactFactory(const ArtifactFactory& other) = delete;
    void operator=(const ArtifactFactory& other) = delete;

    static ArtifactFactory* getFactory();
    Artifact* create(std::vector<bool>& params);
    Artifact* createDamageArtifact();
    Reward* getArtifact(int index);
    void clear();
    int artifactAmount();
};
