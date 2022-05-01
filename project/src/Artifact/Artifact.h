#include <vector>
#include <string>
#include "../LiveObject/LiveObject.h"
#include "../Reward/Reward.h"
#pragma once

enum class ArtifactParams {Combat = 0, Passive, Active};
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
    bool isCombat();
    bool isPassive();
    bool isActive();
    const std::string* sayDescription() override;
    Reward* clone() override;
    Artifact* toArtifact() final {return this;};
    Card* toCard() final {return nullptr;};
};

void createArtifacts();