#include "main.h"
#include "src/Artifact/ArtifactFactory.h"
#include "src/AbstractFactory/WeakFactory.h"
#include "src/AbstractFactory/CommonFactory.h"
#include "src/AbstractFactory/StrongFactory.h"
#include "src/Interface/InterfaceChooser.h"
#include "src/Interface/ConsoleInterface.h"

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
    InterfaceChooser interface;
    if (kChosenInterface == Interface::Console) {
        interface.setStrategy(new ConsoleInterface);
    }
    if (kChosenInterface == Interface::Graphic) {
        //interface.setStrategy(new GraphicInterface);
    }
    if (kChosenInterface == Interface::Network) {
        //interface.setStrategy(new NetworkInterface);
    }
    Client client(interface);
    srand(time(0));
    while (!timeToExit) {
        interface.write("open",  nullptr, nullptr);
        int answer = interface.read();
        if (answer == 1) {
            client.newGame();
        }
        if (answer == 0) {
            timeToExit = true;
        }
        if (answer != 0 && answer != 1) {
            interface.write("unknown", nullptr, nullptr);
        }
    }
    clear();
    interface.write("close", nullptr, nullptr);
    return 0;
}
