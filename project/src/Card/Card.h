#include "../Types/EffectType.h"
#include "../LiveObject/LiveObject.h"
#include "../Reward/Reward.h"
#pragma once

enum class CardType{None = -1, Weak = 0, Common, Strong};
class Card : public Reward {
protected:
    int shieldAmount;
    std::vector<EffectType> buffs;
    int damage;
    std::vector<EffectType> debuffs;
    const std::string* description;

public:
    Card(int newShieldAmount, std::vector<EffectType>& newBuffs, int newDamage,
         std::vector<EffectType>& newDebuffs, const std::string* newDescription);
    Card() : Reward(RewardType::Card) {};

    virtual void use(LiveObject* target, LiveObject* user) = 0;
    const std::string* sayDescription() override;
    std::pair<int, int> realDamDef(LiveObject* user);
    virtual ~Card() = default;
    virtual CardType sayCardType() {return CardType::None;};
    Card* toCard() final {return this;};
    Artifact* toArtifact() final {return nullptr;};
    Reward* clone() override = 0;
};

void createCards();