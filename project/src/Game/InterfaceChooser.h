#include <vector>
#include <string>
#include "../Map/Map.h"
#include "../Const/Constants.h"
#pragma once


class InterfaceChooser {
public:
    static void write(Interface type, const std::string& answer, std::vector<int>* values,
                      std::vector<std::string*>* strings);
    static void showMap(Interface type, Map& map, std::pair<int, int>& position);
    static void showPaths(Interface type, Map& map, std::pair<int, int>& position);
    static void showCombatStatus(Interface type, std::vector<int>& values);
    static void showCard(Interface type, int number, int damage, int defence, std::string* description);
    static int read(Interface type);
};
