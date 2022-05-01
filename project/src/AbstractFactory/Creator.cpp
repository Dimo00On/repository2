#include "Creator.h"

void Creator::setFactory(AbstractFactory *newFactory) {
    factory = newFactory;
}

void Creator::createCard(int damage, int defence, const std::string* description,
                         std::vector<EffectType>& buffs, std::vector<EffectType>& debuffs) {
    factory->createCard(damage, defence, description, buffs, debuffs);
}

void Creator::createEnemy(std::vector<AttackType> &attacks) {
    factory->createEnemy(attacks);
}