#include "main.h"
#include "src/Artifact/ArtifactFactory.h"
#include "src/AbstractFactory/WeakFactory.h"
#include "src/AbstractFactory/CommonFactory.h"
#include "src/AbstractFactory/StrongFactory.h"

void createArtifacts() {
    std::vector<bool> forArtifact(3, false);
    auto factory = ArtifactFactory::getFactory();
    factory->create(forArtifact);
}

void createEnemies() {
    auto weakFactory = WeakFactory::getFactory();
    auto commonFactory = CommonFactory::getFactory();
    auto strongFactory = StrongFactory::getFactory();
    std::vector<EffectType> empty;
    std::vector<AttackType> attacks;
    {
        AttackType attack1(10, 0, empty, empty);
        AttackType attack2(0, 10, empty, empty);
        AttackType attack3(7, 6, empty, empty);
        attacks.push_back(attack1);
        attacks.push_back(attack1);
        attacks.push_back(attack2);
        attacks.push_back(attack2);
        attacks.push_back(attack3);
    }
    weakFactory->createEnemy(attacks);
    attacks.clear();
    {
        AttackType attack1(15, 5, empty, empty);
        AttackType attack2(8, 12, empty, empty);
        AttackType attack3(30, 0, empty, empty);
        attacks.push_back(attack1);
        attacks.push_back(attack1);
        attacks.push_back(attack2);
        attacks.push_back(attack2);
        attacks.push_back(attack3);
    }
    commonFactory->createEnemy(attacks);
    attacks.clear();
    {
        AttackType attack1(20, 10, empty, empty);
        AttackType attack2(10, 20, empty, empty);
        AttackType attack3(40, 0, empty, empty);
        AttackType attack4(0, 50, empty, empty);
        attacks.push_back(attack1);
        attacks.push_back(attack1);
        attacks.push_back(attack2);
        attacks.push_back(attack2);
        attacks.push_back(attack3);
        attacks.push_back(attack4);
    }
    strongFactory->createEnemy(attacks);
    attacks.clear();
}

void createCards() {
    auto weakFactory = WeakFactory::getFactory();
    auto commonFactory = CommonFactory::getFactory();
    auto strongFactory = StrongFactory::getFactory();
    std::vector<EffectType> empty;
    auto emptyDescription = new std::string;
    weakFactory->createCard(6, 0, emptyDescription, empty, empty);
    weakFactory->createCard(0, 5, emptyDescription, empty, empty);
    weakFactory->createCard(3, 2, emptyDescription, empty, empty);
    commonFactory->createCard(12, 0, emptyDescription, empty, empty);
    commonFactory->createCard(0, 10, emptyDescription, empty, empty);
    commonFactory->createCard(6, 5, emptyDescription, empty, empty);
    strongFactory->createCard(25, 0, emptyDescription, empty, empty);
    strongFactory->createCard(0, 20, emptyDescription, empty, empty);
    strongFactory->createCard(15, 10, emptyDescription, empty, empty);
}

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
        std::cout << "Choose command:" << '\n';
        std::cout << "Start new game - 1" << '\n';
        std::cout << "Exit - 0" << '\n';
        std::string command;
        std::cin >> command;
        if (command == "1") {
            client.newGame();
        }
        if (command == "0") {
            timeToExit = true;
        }
    }
    clear();
    std::cout << "exit" << '\n';
    return 0;
}
