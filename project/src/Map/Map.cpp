#include "Map.h"
#include <cstdlib>
#include "../Const/Constants.h"


void Map::createNewMap(int size1, int size2) {
    rooms.resize(size1);
    for (int i = 0; i < size1; ++i) {
        rooms[i].resize(size2);
        for (int j = 0; j < size2; ++j) {
            if (i == 0 && j == 0) {
                ChillRoomFactory factory;
                auto chill = dynamic_cast<ChillRoom*>(factory.create(Difficulty::None));
                chill->setEmpty(true);
                rooms[i][j] = chill;
            }
            if (i == size1 - 1) {
                EndRoomFactory factory;
                auto end = factory.create(Difficulty::None);
                rooms[i][j] = end;
                continue;
            }
            if (i == size1 - 2) {
                CombatRoomFactory factory;
                auto boss = factory.create(Difficulty::Hard);
                rooms[i][j] = boss;
                continue;
            }
            if (i < size1 - 2) {
                int randomNumber = rand() % kRandomLimit;
                if (randomNumber <= kChillRandomLimit) {
                    ChillRoomFactory factory;
                    auto chill = factory.create(Difficulty::None);
                    rooms[i][j] = chill;
                }
                if (randomNumber >= kCommonFightRandomLimit) {
                    CombatRoomFactory factory;
                    auto fight = factory.create(Difficulty::Normal);
                    rooms[i][j] = fight;
                }
                if (randomNumber > kChillRandomLimit && randomNumber < kCommonFightRandomLimit) {
                    CombatRoomFactory factory;
                    auto fight = factory.create(Difficulty::Easy);
                    rooms[i][j] = fight;
                }
            }
        }
    }
}

Map::~Map(){
    for (auto & row : rooms) {
        for (auto & room : row) {
            delete room;
        }
    }
}