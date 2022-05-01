#include "InterfaceChooser.h"

InterfaceChooser::InterfaceChooser() {
    strategy = nullptr;
}

void InterfaceChooser::setStrategy(InterfaceStrategy* newStrategy) {
    delete strategy;
    strategy = newStrategy;
}

void InterfaceChooser::write(const std::string& answer, std::vector<int>* values,
                  std::vector<const std::string*>* strings) {
    strategy->write(answer, values, strings);
}
void InterfaceChooser::showMap(Map& map, std::pair<int, int>& position) {
    strategy->showMap(map, position);
}
void InterfaceChooser::showPaths(Map& map, std::pair<int, int>& position) {
    strategy->showPaths(map, position);
}
void InterfaceChooser::showCombatStatus(std::vector<int>& values,
                                        const std::vector<EffectType>& enemyEffects,
                                        const std::vector<EffectType>& playerEffects) {
    strategy->showCombatStatus(values, enemyEffects, playerEffects);
}
void InterfaceChooser::showCard(int number, int damage, int defence, const std::string* description) {
    strategy->showCard(number, damage, defence, description);
}
int InterfaceChooser::read() {
    return strategy->read();
}

void InterfaceChooser::showArtifact(int number, const std::string* description) {
    strategy->showArtifact(number, description);
}
