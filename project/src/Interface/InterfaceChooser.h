#include <vector>
#include <string>
#include "../Map/Map.h"
#include "../Const/Constants.h"
#include "../Types/EffectType.h"
#include "InterfaceStrategy.h"
#pragma once


class InterfaceChooser {
private:
    InterfaceStrategy* strategy;

public:
    InterfaceChooser();
    void setStrategy(InterfaceStrategy* newStrategy);
    void write(const std::string& answer, std::vector<int>* values,
                      std::vector<const std::string*>* strings);
    void showMap(Map& map, std::pair<int, int>& position);
    void showPaths(Map& map, std::pair<int, int>& position);
    void showCombatStatus(std::vector<int>& values, const std::vector<EffectType>& enemyEffects,
                                 const std::vector<EffectType>& playerEffects);
    void showCard(int number, int damage, int defence, const std::string* description);
    int read();
    void showArtifact(int number, const std::string* description);
};
