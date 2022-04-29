#include "Card.h"
#include "../AbstractFactory/WeakFactory.h"
#include "../AbstractFactory/CommonFactory.h"
#include "../AbstractFactory/StrongFactory.h"

Card::Card(int newShieldAmount, std::vector<EffectType>& newBuffs, int newDamage,
                   std::vector<EffectType>& newDebuffs, const std::string* newDescription) :
        Reward(RewardType::Card), shieldAmount(newShieldAmount), buffs(newBuffs),
        damage(newDamage), debuffs(newDebuffs), description(newDescription) {}

std::pair<int, int> Card::realDamDef(LiveObject* user) {
    float realDamage = damage;
    float realDefence = shieldAmount;
    std::vector<EffectType> effects = user->sayEffects();
    for (int i = 0; i < effects.size(); ++i) {
        realDamage += effects[i].sayAttackPower();
        realDefence += effects[i].sayDefencePower();
    }
    for (int i = 0; i < effects.size(); ++i) {
        realDamage *= effects[i].sayAttackScale();
        realDefence *= effects[i].sayDefenceScale();
    }
    return std::make_pair<int, int>(realDamage, realDefence);
}

const std::string* Card::sayDescription() {
    return description;
}

void createCards() {
    auto weakFactory = WeakFactory::getFactory();
    auto commonFactory = CommonFactory::getFactory();
    auto strongFactory = StrongFactory::getFactory();
    std::vector<EffectType> empty;
    weakFactory->createCard(6, 0, &kEmptyDescription, empty, empty);
    weakFactory->createCard(0, 5, &kEmptyDescription, empty, empty);
    weakFactory->createCard(3, 2, &kEmptyDescription, empty, empty);
    commonFactory->createCard(12, 0, &kEmptyDescription, empty, empty);
    commonFactory->createCard(0, 10, &kEmptyDescription, empty, empty);
    commonFactory->createCard(6, 5, &kEmptyDescription, empty, empty);
    strongFactory->createCard(25, 0, &kEmptyDescription, empty, empty);
    strongFactory->createCard(0, 20, &kEmptyDescription, empty, empty);
    strongFactory->createCard(15, 10, &kEmptyDescription, empty, empty);
}