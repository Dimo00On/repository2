#include "main.h"
#include "src/Artifact/ArtifactFactory.h"
#include "src/AbstractFactory/WeakFactory.h"
#include "src/AbstractFactory/CommonFactory.h"
#include "src/AbstractFactory/StrongFactory.h"
#include "src/Game/InterfaceChooser.h"

void preCalc() {
    createArtifacts();
    createCards();
    createEnemies();
}

void clear() {
    auto artifactFactory = ArtifactFactory::getFactory();
    delete artifactFactory;
    auto weakFactory = WeakFactory::getFactory();
    delete weakFactory;
    auto commonFactory = CommonFactory::getFactory();
    delete commonFactory;
    auto strongFactory = StrongFactory::getFactory();
    delete strongFactory;
}

int main() {
    //создать карты, атаки, артефакты и тд
    preCalc();
    Client client;
    srand(time(0));
    while (!timeToExit) {
        InterfaceChooser::write(kChosenInterface, "open",  nullptr, nullptr);
        int answer = InterfaceChooser::read(kChosenInterface);
        if (answer == 1) {
            client.newGame();
        }
        if (answer == 0) {
            timeToExit = true;
        }
        if (answer != 0 && answer != 1) {
            InterfaceChooser::write(kChosenInterface, "unknown", nullptr, nullptr);
        }
    }
    clear();
    InterfaceChooser::write(kChosenInterface, "close", nullptr, nullptr);
    return 0;
}
