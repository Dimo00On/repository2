#include "AbstractFactory.h"
#include "Artifact.h"
#include "Card.h"

namespace Cards{
    extern std::vector<CommonCard*> allCommonCards;
    extern std::vector<StrongCard*> allStrongCards;
}

namespace Artifacts{
    extern std::vector<Artifact> allArtifacts;
}

AbstractEnemy* WeakFactory::createEnemy(std::vector<AttackType>& attacks) {
    auto enemy = new WeakEnemy;
    enemy->attackTypes = attacks;
    int chosenReward = rand() % static_cast<int>(Cards::allCommonCards.size());
    CommonFactory factory;
    CommonCard* a = Cards::allCommonCards[chosenReward];
    enemy->reward = dynamic_cast<CommonCard*>(factory.createCard(a->damage, a->shieldAmount,
                                                                 a->description, a->buffs, a->debuffs));
    return enemy;
}

Card* WeakFactory::createCard(int damage, int defence, std::string* description,
                 std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs) {
    auto card = new WeakCard;
    card->damage = damage;
    card->shieldAmount = defence;
    card->buffs = buffs;
    card->debuffs = debuffs;
    card->description = description;
    return card;
}

AbstractEnemy* CommonFactory::createEnemy(std::vector<AttackType>& attacks) {
    auto enemy = new CommonEnemy;
    enemy->attackTypes = attacks;
    int chosenReward = rand() % static_cast<int>(Cards::allStrongCards.size());
    StrongFactory factory;
    StrongCard* a = Cards::allStrongCards[chosenReward];
    enemy->reward = dynamic_cast<StrongCard*>(factory.createCard(a->damage, a->shieldAmount,
                                                                 a->description, a->buffs, a->debuffs));
    return enemy;
}

Card* CommonFactory::createCard(int damage, int defence, std::string* description,
                                std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs) {
    auto card = new CommonCard;
    card->damage = damage;
    card->shieldAmount = defence;
    card->buffs = buffs;
    card->debuffs = debuffs;
    card->description = description;
    return card;
}

AbstractEnemy* StrongFactory::createEnemy(std::vector<AttackType>& attacks) {
    auto enemy = new StrongEnemy;
    enemy->attackTypes = attacks;
    int chosenReward = rand() % static_cast<int>(Artifacts::allArtifacts.size());
    auto newArtifact = new Artifact(Artifacts::allArtifacts[chosenReward]);
    enemy->reward = newArtifact;
    return enemy;
}


Card* StrongFactory::createCard(int damage, int defence, std::string* description,
                                std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs) {
    auto card = new StrongCard;
    card->damage = damage;
    card->shieldAmount = defence;
    card->buffs = buffs;
    card->debuffs = debuffs;
    card->description = description;
    return card;
}