#include "Client.h"
#include "../AbstractFactory/AbstractFactory.h"
#include "GameProcess.h"
#include "../AbstractFactory/CommonFactory.h"
#include "../AbstractFactory/WeakFactory.h"
#include "../AbstractFactory/StrongFactory.h"
#include "InterfaceChooser.h"

extern bool timeToExit;

void Client::newGame() {
    Map map;
    map.createNewMap(kBaseMapSize2, kBaseMapSize1);
    PlayerGameObject player;
    GameProcess game(map, player);
    while (!timeToExit) {
        game.changingPosition();
        if (!timeToExit) {
            auto currentRoom = map.showMap()[game.position.first][game.position.second];
            if (currentRoom->sayType() == RoomType::End) {
                InterfaceChooser::write(kChosenInterface, "win game", nullptr, nullptr);
                InterfaceChooser::read(kChosenInterface);
                timeToExit = true;
            }
            if (currentRoom->sayType() == RoomType::Chill) {
                auto room = dynamic_cast<ChillRoom *>(currentRoom);
                if (!room->sayIsEmpty()) {
                    game.startChill();
                    room->setEmpty(true);
                } else {
                    InterfaceChooser::write(kChosenInterface, "empty", nullptr, nullptr);
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
                    InterfaceChooser::write(kChosenInterface, "empty", nullptr, nullptr);
                }
            }
        }
    }
}