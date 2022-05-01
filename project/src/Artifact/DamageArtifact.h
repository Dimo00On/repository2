#include "Artifact.h"
#include "../LiveObject/LiveObject.h"

class DamageArtifact : public Artifact {
private:
    float multiplier;

public:
    explicit DamageArtifact(std::vector<bool>& params) : Artifact(params) {};
    DamageArtifact(const DamageArtifact& other) = default;
    void setMultiplier(float value);
    void doSomething(LiveObject* user, LiveObject* target) override;
    Reward* clone() override;
};
