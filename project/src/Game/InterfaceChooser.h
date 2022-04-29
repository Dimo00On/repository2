#include <vector>
#include <string>
#include "../Map/Map.h"
#include "../Const/Constants.h"
#include "../Types/EffectType.h"
#pragma once


class InterfaceChooser {
public:
    static void write(Interface type, const std::string& answer, std::vector<int>* values,
                      std::vector<const std::string*>* strings);
    static void showMap(Interface type, Map& map, std::pair<int, int>& position);
    static void showPaths(Interface type, Map& map, std::pair<int, int>& position);
    static void showCombatStatus(Interface type, std::vector<int>& values, const std::vector<EffectType>& enemyEffects,
                                 const std::vector<EffectType>& playerEffects);
    static void showCard(Interface type, int number, int damage, int defence, const std::string* description);
    static int read(Interface type);
    static void showArtifact(Interface type, int number, const std::string* description);
};
