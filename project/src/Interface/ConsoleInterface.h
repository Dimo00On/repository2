#include <iostream>
#include <string>
#include <vector>
#include "InterfaceStrategy.h"
#pragma once

class ConsoleInterface : public InterfaceStrategy {
public:
    void write(const std::string& answer, std::vector<int>* values,
               std::vector<const std::string*>* strings) override;
    void showMap(Map& map, std::pair<int, int>& position) override;
    void showPaths(Map& map, std::pair<int, int>& position) override;
    void showCombatStatus(std::vector<int>& values, const std::vector<EffectType>& enemyEffects,
                                 const std::vector<EffectType>& playerEffects) override;
    void showCard(int number, int damage, int defence, const std::string* description) override;
    int read() override;
    void showArtifact(int number, const std::string* description) override;
};