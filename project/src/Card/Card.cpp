#include "Card.h"
#include "../AbstractFactory/WeakFactory.h"
#include "../AbstractFactory/CommonFactory.h"
#include "../AbstractFactory/StrongFactory.h"

Card::Card(int newShieldAmount, std::vector<EffectType>& newBuffs, int newDamage,
                   std::vector<EffectType>& newDebuffs, std::string *newDescription) :
        shieldAmount(newShieldAmount), buffs(newBuffs), damage(newDamage), debuffs(newDebuffs),
        description(newDescription) {}

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

std::string& Card::sayDescription() {
    return *description;
}

void createCards() {
    auto weakFactory = WeakFactory::getFactory();
    auto commonFactory = CommonFactory::getFactory();
    auto strongFactory = StrongFactory::getFactory();
    std::vector<EffectType> empty;
    auto emptyDescription = new std::string;
    weakFactory->createCard(6, 0, emptyDescription, empty, empty);
    weakFactory->createCard(0, 5, emptyDescription, empty, empty);
    weakFactory->createCard(3, 2, emptyDescription, empty, empty);
    commonFactory->createCard(12, 0, emptyDescription, empty, empty);
    commonFactory->createCard(0, 10, emptyDescription, empty, empty);
    commonFactory->createCard(6, 5, emptyDescription, empty, empty);
    strongFactory->createCard(25, 0, emptyDescription, empty, empty);
    strongFactory->createCard(0, 20, emptyDescription, empty, empty);
    strongFactory->createCard(15, 10, emptyDescription, empty, empty);
}