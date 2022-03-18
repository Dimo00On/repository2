#include "main.h"

namespace Cards{
    extern std::vector<WeakCard*> allWeakCards;
    extern std::vector<CommonCard*> allCommonCards;
    extern std::vector<StrongCard*> allStrongCards;
}

namespace Enemies{
    extern std::vector<WeakEnemy*> allWeakEnemies;
    extern std::vector<CommonEnemy*> allCommonEnemies;
    extern std::vector<StrongEnemy*> allStrongEnemies;
}

namespace Artifacts{
    extern std::vector<Artifact> allArtifacts;
}

void preCalc() {
    WeakFactory weakFactory;
    CommonFactory commonFactory;
    StrongFactory strongFactory;
    std::vector<EffectType> empty;
    std::string* emptyDescription = new std::string;
    std::vector<bool> forArtifact(3, false);
    Artifacts::allArtifacts.emplace_back(forArtifact);
    Cards::allWeakCards.push_back(dynamic_cast<WeakCard*>(weakFactory.createCard(6, 0, emptyDescription, empty, empty)));
    Cards::allWeakCards.push_back(dynamic_cast<WeakCard*>(weakFactory.createCard(0, 5, emptyDescription, empty, empty)));
    Cards::allWeakCards.push_back(dynamic_cast<WeakCard*>(weakFactory.createCard(3, 2, emptyDescription, empty, empty)));
    Cards::allCommonCards.push_back(dynamic_cast<CommonCard*>(commonFactory.createCard(12, 0, emptyDescription, empty, empty)));
    Cards::allCommonCards.push_back(dynamic_cast<CommonCard*>(commonFactory.createCard(0, 10, emptyDescription, empty, empty)));
    Cards::allCommonCards.push_back(dynamic_cast<CommonCard*>(commonFactory.createCard(6, 5, emptyDescription, empty, empty)));
    Cards::allStrongCards.push_back(dynamic_cast<StrongCard*>(strongFactory.createCard(25, 0, emptyDescription, empty, empty)));
    Cards::allStrongCards.push_back(dynamic_cast<StrongCard*>(strongFactory.createCard(0, 20, emptyDescription, empty, empty)));
    Cards::allStrongCards.push_back(dynamic_cast<StrongCard*>(strongFactory.createCard(15, 10, emptyDescription, empty, empty)));
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
    Enemies::allWeakEnemies.push_back(dynamic_cast<WeakEnemy*>(weakFactory.createEnemy(attacks)));
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
    Enemies::allCommonEnemies.push_back(dynamic_cast<CommonEnemy*>(commonFactory.createEnemy(attacks)));
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
    Enemies::allStrongEnemies.push_back(dynamic_cast<StrongEnemy*>(strongFactory.createEnemy(attacks)));
    attacks.clear();
}

void clear() {
    Enemies::allStrongEnemies.clear();
    Enemies::allCommonEnemies.clear();
    Enemies::allWeakEnemies.clear();
    Cards::allWeakCards.clear();
    Cards::allCommonCards.clear();
    Cards::allStrongCards.clear();
    Artifacts::allArtifacts.clear();
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
