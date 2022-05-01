#include "Client.h"
#include "../AbstractFactory/AbstractFactory.h"
#include "GameProcess.h"
#include "../AbstractFactory/CommonFactory.h"
#include "../AbstractFactory/WeakFactory.h"
#include "../AbstractFactory/StrongFactory.h"
#include "../Interface/InterfaceChooser.h"

extern bool timeToExit;

Client::Client(InterfaceChooser newInterface) : interface(newInterface) {};

void Client::newGame() {
    Map map;
    map.createNewMap(kBaseMapSize2, kBaseMapSize1);
    PlayerGameObject player;
    GameProcess game(map, player, interface);
    while (!timeToExit) {
        game.changingPosition();
        if (!timeToExit) {
            auto currentRoom = map.showMap()[game.position.first][game.position.second];
            if (currentRoom->sayType() == RoomType::End) {
                interface.write("win game", nullptr, nullptr);
                interface.read();
                timeToExit = true;
            }
            if (currentRoom->sayType() == RoomType::Chill) {
                if (!currentRoom->sayIsEmpty()) {
                    game.startChill();
                    currentRoom->setEmpty(true);
                } else {
                    interface.write("empty", nullptr, nullptr);
                }
            }
            if (currentRoom->sayType() == RoomType::Combat) {
                if (!currentRoom->sayIsEmpty()) {
                    AbstractEnemy* enemy;
                    AbstractFactory* factory;
                    if (currentRoom->sayDifficulty()== Difficulty::Easy) {
                        factory = WeakFactory::getFactory();
                    }
                    if (currentRoom->sayDifficulty() == Difficulty::Normal) {
                        factory = CommonFactory::getFactory();
                    }
                    if (currentRoom->sayDifficulty() == Difficulty::Hard) {
                        factory = StrongFactory::getFactory();
                    }
                    int chosenEnemy = rand() % static_cast<int>(factory->enemyAmount());
                    enemy = factory->getEnemy(chosenEnemy);
                    game.startCombat(enemy);
                    currentRoom->setEmpty(true);
                } else {
                    interface.write("empty", nullptr, nullptr);
                }
            }
        }
    }
}