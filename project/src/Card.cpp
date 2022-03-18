#include "Card.h"

namespace Cards {
    std::vector<Card*> allCards;
    std::vector<WeakCard*> allWeakCards;
    std::vector<CommonCard*> allCommonCards;
    std::vector<StrongCard*> allStrongCards;
}

void WeakCard::use(LiveObject* target, LiveObject* user) {
    std::pair<int, int> damDef = realDamDef(user);
    if (target->defence < damDef.first) {
        damDef.first -= target->defence;
        target->defence = 0;
        target->hp -= damDef.first;
    } else {
        target->defence -= damDef.first;
    }
    user->defence += damDef.second;
    for (int i = 0; i < buffs.size(); ++i) {
        user->currentEffects.push_back(buffs[i]);
    }
    for (int i = 0; i < debuffs.size(); ++i) {
        target->currentEffects.push_back(debuffs[i]);
    }
}

std::pair<int, int> WeakCard::realDamDef(LiveObject* user) {
    float realDamage = damage;
    float realDefence = shieldAmount;
    for (int i = 0; i < user->currentEffects.size(); ++i) {
        realDamage += user->currentEffects[i].attackInfluencePower;
        realDefence += user->currentEffects[i].defenceInfluencePower;
    }
    for (int i = 0; i < user->currentEffects.size(); ++i) {
        realDamage *= user->currentEffects[i].attackInfluenceScale;
        realDefence *= user->currentEffects[i].defenceInfluenceScale;
    }
    return std::make_pair<int, int>(realDamage, realDefence);
}

std::string& WeakCard::sayDescription() {
    return *description;
}

void CommonCard::use(LiveObject* target, LiveObject* user) {
    std::pair<int, int> damDef = realDamDef(user);
    if (target->defence < damDef.first) {
        damDef.first -= target->defence;
        target->defence = 0;
        target->hp -= damDef.first;
    } else {
        target->defence -= damDef.first;
    }
    user->defence += damDef.second;
    for (int i = 0; i < buffs.size(); ++i) {
        user->currentEffects.push_back(buffs[i]);
    }
    for (int i = 0; i < debuffs.size(); ++i) {
        target->currentEffects.push_back(debuffs[i]);
    }
}

std::pair<int, int> CommonCard::realDamDef(LiveObject* user) {
    float realDamage = damage;
    float realDefence = shieldAmount;
    for (int i = 0; i < user->currentEffects.size(); ++i) {
        realDamage += user->currentEffects[i].attackInfluencePower;
        realDefence += user->currentEffects[i].defenceInfluencePower;
    }
    for (int i = 0; i < user->currentEffects.size(); ++i) {
        realDamage *= user->currentEffects[i].attackInfluenceScale;
        realDefence *= user->currentEffects[i].defenceInfluenceScale;
    }
    return std::make_pair<int, int>(realDamage, realDefence);
}

std::string& CommonCard::sayDescription() {
    return *description;
}

void StrongCard::use(LiveObject* target, LiveObject* user) {
    std::pair<int, int> damDef = realDamDef(user);
    if (target->defence < damDef.first) {
        damDef.first -= target->defence;
        target->defence = 0;
        target->hp -= damDef.first;
    } else {
        target->defence -= damDef.first;
    }
    user->defence += damDef.second;
    for (int i = 0; i < buffs.size(); ++i) {
        user->currentEffects.push_back(buffs[i]);
    }
    for (int i = 0; i < debuffs.size(); ++i) {
        target->currentEffects.push_back(debuffs[i]);
    }
}

std::pair<int, int> StrongCard::realDamDef(LiveObject* user) {
    float realDamage = damage;
    float realDefence = shieldAmount;
    for (int i = 0; i < user->currentEffects.size(); ++i) {
        realDamage += user->currentEffects[i].attackInfluencePower;
        realDefence += user->currentEffects[i].defenceInfluencePower;
    }
    for (int i = 0; i < user->currentEffects.size(); ++i) {
        realDamage *= user->currentEffects[i].attackInfluenceScale;
        realDefence *= user->currentEffects[i].defenceInfluenceScale;
    }
    return std::make_pair<int, int>(realDamage, realDefence);
}

std::string& StrongCard::sayDescription() {
    return *description;
}