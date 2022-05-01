#include <iostream>
#include <string>
#include <vector>
#include "../Map/Map.h"
#pragma once

class ConsoleInterface {
public:
    static void write(const std::string& answer, std::vector<int>* values,
               std::vector<std::string*>* strings);
    static void showMap(Map& map, std::pair<int, int>& position);
    static void showPaths(Map& map, std::pair<int, int>& position);
    static void showCombatStatus(std::vector<int>& values);
    static void showCard(int number, int damage, int defence, std::string* description);
    static int readNumber();
};