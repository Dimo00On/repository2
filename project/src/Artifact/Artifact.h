#include <vector>
#include <string>
#include "../LiveObject/LiveObject.h"
#include "../Reward/Reward.h"
#pragma once

enum class ArtifactParams {Combat = 0, Passive, Active};
enum class ArtifactType{None = -1, DamageArtifact = 0};
class Artifact : public Reward {
protected:
    bool isCombatType;
    bool isPassiveType;
    bool isActiveType;
    const std::string* description;

public:
    explicit Artifact(std::vector<bool>& params);
    Artifact() : Reward(RewardType::Artifact) {};
    virtual ~Artifact() {};
    Artifact(const Artifact& other) = default;
    virtual void doSomething(LiveObject* user, LiveObject* target) {};
    void setDescription(const std::string* newDescription);
    virtual ArtifactType sayArtifactType() {return ArtifactType::None;};
    bool isCombat();
    bool isPassive();
    bool isActive();
    const std::string* sayDescription() override;
};

void createArtifacts();