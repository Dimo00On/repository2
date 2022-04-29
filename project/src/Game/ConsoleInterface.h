#include <iostream>
#include <string>
#include <vector>
#include "../Map/Map.h"
#include "../Types/EffectType.h"
#pragma once

class ConsoleInterface {
public:
    static void write(const std::string& answer, std::vector<int>* values,
               std::vector<const std::string*>* strings);
    static void showMap(Map& map, std::pair<int, int>& position);
    static void showPaths(Map& map, std::pair<int, int>& position);
    static void showCombatStatus(std::vector<int>& values, const std::vector<EffectType>& enemyEffects,
                                 const std::vector<EffectType>& playerEffects);
    static void showCard(int number, int damage, int defence, const std::string* description);
    static int readNumber();
    static void showArtifact(int number, const std::string* description);
};