#include "Client.h"
#include "AbstractFactory.h"
#include "Enemy.h"

extern bool timeToExit;

namespace Enemies{
    extern std::vector<WeakEnemy*> allWeakEnemies;
    extern std::vector<CommonEnemy*> allCommonEnemies;
    extern std::vector<StrongEnemy*> allStrongEnemies;
    extern std::vector<AbstractEnemy*> allDeadEnemies;
}

void Client::newGame() {
    Map map;
    map.createNewMap(kBaseMapSize2, kBaseMapSize1);
    PlayerGameObject player;
    GameProcess game(map, player);
    while (!timeToExit) {
        game.changingPosition();
        if (!timeToExit) {
            auto currentRoom = map.rooms[game.position.first][game.position.second];
            if (currentRoom->sayType() == 0) {
                std::cout << "Congratulations! You win!" << '\n';
                std::cout << "Print something to exit" << '\n';
                std::string command;
                std::cin >> command;
                timeToExit = true;
            }
            if (currentRoom->sayType() == 1) {
                auto room = dynamic_cast<ChillRoom *>(currentRoom);
                if (!room->isEmpty) {
                    game.startChill();
                    room->isEmpty = true;
                } else {
                    std::cout << "You have already been there" << '\n';
                }
            }
            if (currentRoom->sayType() == 2) {
                auto room = dynamic_cast<CombatRoom *>(currentRoom);
                if (!room->isEmpty) {
                    AbstractEnemy *enemy;
                    if (room->difficulty == 1) {
                        WeakFactory factory;
                        int chosenEnemy = rand() % static_cast<int>(Enemies::allWeakEnemies.size());
                        enemy = factory.createEnemy(Enemies::allWeakEnemies[chosenEnemy]->attackTypes);
                    }
                    if (room->difficulty == 2) {
                        CommonFactory factory;
                        int chosenEnemy = rand() % static_cast<int>(Enemies::allCommonEnemies.size());
                        enemy = factory.createEnemy(Enemies::allCommonEnemies[chosenEnemy]->attackTypes);
                    }
                    if (room->difficulty == 3) {
                        StrongFactory factory;
                        int chosenEnemy = rand() % static_cast<int>(Enemies::allStrongEnemies.size());
                        enemy = factory.createEnemy(Enemies::allStrongEnemies[chosenEnemy]->attackTypes);
                    }
                    game.startCombat(enemy);
                    room->isEmpty = true;
                } else {
                    std::cout << "You have already been there" << '\n';
                }
            }
        }
    }
    for (auto enemy : Enemies::allDeadEnemies) {
        delete enemy;
    }
}