#include "../Types/EffectType.h"
#include "../Map/Map.h"
#pragma once

class InterfaceStrategy {
public:
    virtual ~InterfaceStrategy() = default;
    virtual  void write(const std::string& answer, std::vector<int>* values,
                      std::vector<const std::string*>* strings) = 0;
    virtual  void showMap(Map& map, std::pair<int, int>& position) = 0;
    virtual  void showPaths(Map& map, std::pair<int, int>& position) = 0;
    virtual  void showCombatStatus(std::vector<int>& values, const std::vector<EffectType>& enemyEffects,
                                 const std::vector<EffectType>& playerEffects) = 0;
    virtual  void showCard(int number, int damage, int defence, const std::string* description) = 0;
    virtual int read() = 0;
    virtual void showArtifact(int number, const std::string* description) = 0;
};