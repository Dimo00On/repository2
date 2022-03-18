#include "Map.h"

void Map::createNewMap(int size1, int size2) {
    rooms.resize(size1);
    for (int i = 0; i < size1; ++i) {
        rooms[i].resize(size2);
        for (int j = 0; j < size2; ++j) {
            if (i == 0 && j == 0) {
                ChillRoomFactory factory;
                auto chill = dynamic_cast<ChillRoom*>(factory.create(0));
                chill->isEmpty = true;
                rooms[i][j] = chill;
            }
            if (i == size1 - 1) {
                EndRoomFactory factory;
                auto end = factory.create(0);
                rooms[i][j] = end;
                continue;
            }
            if (i == size1 - 2) {
                CombatRoomFactory factory;
                auto boss = factory.create(3);
                rooms[i][j] = boss;
                continue;
            }
            if (i < size1 - 2) {
                int randomNumber = rand() % kRandomLimit;
                if (randomNumber <= kChillRandomLimit) {
                    ChillRoomFactory factory;
                    auto chill = factory.create(0);
                    rooms[i][j] = chill;
                }
                if (randomNumber >= kCommonFightRandomLimit) {
                    CombatRoomFactory factory;
                    auto fight = factory.create(2);
                    rooms[i][j] = fight;
                }
                if (randomNumber > kChillRandomLimit && randomNumber < kCommonFightRandomLimit) {
                    CombatRoomFactory factory;
                    auto fight = factory.create(1);
                    rooms[i][j] = fight;
                }
            }
        }
    }
}

Map::~Map(){
    for (size_t i = 0; i < rooms.size(); ++i) {
        for (size_t j = 0; j < rooms[i].size(); ++j) {
            delete rooms[i][j];
        }
    }
}