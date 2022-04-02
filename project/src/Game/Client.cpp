#include "Client.h"
#include "../AbstractFactory/AbstractFactory.h"
#include "GameProcess.h"
#include "../AbstractFactory/CommonFactory.h"
#include "../AbstractFactory/WeakFactory.h"
#include "../AbstractFactory/StrongFactory.h"

extern bool timeToExit;

void Client::newGame() {
    Map map;
    map.createNewMap(kBaseMapSize2, kBaseMapSize1);
    PlayerGameObject player;
    GameProcess game(map, player);
    while (!timeToExit) {
        game.changingPosition();
        if (!timeToExit) {
            auto currentRoom = map.rooms[game.position.first][game.position.second];
            if (currentRoom->sayType() == RoomType::End) {
                std::cout << "Congratulations! You win!" << '\n';
                std::cout << "Print something to exit" << '\n';
                std::string command;
                std::cin >> command;
                timeToExit = true;
            }
            if (currentRoom->sayType() == RoomType::Chill) {
                auto room = dynamic_cast<ChillRoom *>(currentRoom);
                if (!room->sayIsEmpty()) {
                    game.startChill();
                    room->setEmpty(true);
                } else {
                    std::cout << "You have already been there" << '\n';
                }
            }
            if (currentRoom->sayType() == RoomType::Combat) {
                auto room = dynamic_cast<CombatRoom *>(currentRoom);
                if (!room->sayIsEmpty()) {
                    AbstractEnemy* enemy;
                    AbstractFactory* factory;
                    if (room->sayDifficulty()== Difficulty::Easy) {
                        factory = dynamic_cast<AbstractFactory*>(WeakFactory::getFactory());
                    }
                    if (room->sayDifficulty() == Difficulty::Normal) {
                        factory = dynamic_cast<AbstractFactory*>(CommonFactory::getFactory());
                    }
                    if (room->sayDifficulty() == Difficulty::Hard) {
                        factory = dynamic_cast<AbstractFactory*>(StrongFactory::getFactory());
                    }
                    int chosenEnemy = rand() % static_cast<int>(factory->enemyAmount());
                    enemy = factory->getEnemy(chosenEnemy);
                    game.startCombat(enemy);
                    room->setEmpty(true);
                } else {
                    std::cout << "You have already been there" << '\n';
                }
            }
        }
    }
}