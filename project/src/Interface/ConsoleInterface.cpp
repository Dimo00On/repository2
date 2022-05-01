#include "ConsoleInterface.h"
#include "../Const/Constants.h"
#include "../Types/EffectType.h"

void ConsoleInterface::write(const std::string& answer, std::vector<int>* values,
                             std::vector<const std::string*>* strings) {
    if (answer == "\n") {
        std::cout << '\n';
    }
    if (answer == "close") {
        std::cout << "exit" << '\n';
    }
    if (answer == "open") {
        std::cout << "Choose command:" << '\n';
        std::cout << "Start new game - 1" << '\n';
        std::cout << "Exit - 0" << '\n';
    }
    if (answer == "empty") {
        std::cout << "You have already been there" << '\n';
    }
    if (answer == "win game") {
        std::cout << "Congratulations! You win!" << '\n';
        std::cout << "Print something to exit" << '\n';
    }
    if (answer ==  "rest") {
        std::cout << "You rested and restored some hp(" << (*values)[0] << ")" << '\n';
    }
    if (answer == "unknown") {
        std::cout << "Unknown command" << '\n';
    }
    if (answer == "unknown card") {
        std::cout << "Unknown Command, print 0 to Exit or number to use card or artifact" << '\n';
    }
    if (answer == "dead") {
        std::cout << "You died" << '\n';
        std::cout << "Print something to exit" << '\n';
    }
    if (answer == "kill") {
        std::cout << "You killed enemy. You get a reward - ";
        if ((*values)[0] == 1) {
            std::cout << "common card: " << '\n';
            std::cout << *((*strings)[0]);
            std::cout << "Deals " << (*values)[1] << " damage and give " << (*values)[2] << " shield" << '\n';
        }
        if ((*values)[0] == 2) {
            std::cout << "strong card: " << '\n';
            std::cout << *((*strings)[0]);
            std::cout << "Deals " << (*values)[1] << " damage and give " << (*values)[2] << " shield" << '\n';
        }
        if ((*values)[0] == 3) {
            std::cout << "strange useless artifact:" << '\n' << *((*strings)[0]) << '\n';
        }
    }

}

void ConsoleInterface::showMap(Map& map, std::pair<int, int>& position) {
    for (int i = 0; i < map.showMap()[0].size(); ++i) {
        for (int j = position.first - 1; j < static_cast<int>(map.showMap().size()); ++j) {
            if (j == position.first - 1) {
                if (i == position.second) {
                    std::cout << "you here ->|";
                }
                else {
                    std::cout << "           |";
                }
            } else {
                if (j == position.first && i == position.second) {
                    std::cout << "you|";
                } else {
                    auto thisRoom = map.showMap()[j][i];
                    if (thisRoom->sayIsEmpty()) {
                        std::cout << " . |";
                    } else {
                        if (thisRoom->sayType() == RoomType::Chill) {
                            std::cout << " " << static_cast<int>(thisRoom->sayDifficulty()) << " |";
                        }
                        if (thisRoom->sayType() == RoomType::Combat) {
                            std::cout << " " << static_cast<int>(thisRoom->sayDifficulty()) << " |";
                        }
                        if (thisRoom->sayType() == RoomType::End) {
                            std::cout << "end|";
                        }
                    }
                }
            }
        }
        std::cout <<'\n';
    }
}

void ConsoleInterface::showPaths(Map &map, std::pair<int, int> &position) {
    std::cout << "|1|2| |" << '\n';
    std::cout << "|I|3|4|" << '\n';
    std::cout << "|5|6| |" << '\n';
    std::cout << "Choose command:" << '\n';
    std::cout << "Exit - 0" << '\n';
    int size = map.showMap().size();
    if (position.second > 0) {
        std::cout << "Go up - 1" << '\n';
        if (position.first + 1 < size) {
            std::cout << "Go up-right - 2" << '\n';
        }
    }
    if (position.first + 1 < size) {
        std::cout << "Go right - 3" << '\n';
        if (position.first + 3 < size) {
            std::cout << "Go double right - 4" << '\n';
        }
    }
    if (position.second + 1 < map.showMap()[position.first].size()) {
        std::cout << "Go down - 5" << '\n';
        if (position.first + 1 < size) {
            std::cout << "Go down-right - 6" << '\n';
        }
    }
}

void ConsoleInterface::showCombatStatus(std::vector<int> &values,
                                        const std::vector<EffectType>& enemyEffects,
                                        const std::vector<EffectType>& playerEffects) {
    std::cout << '\n' << "Enemy want to deal " << values[0] << " damage to you ";
    std::cout << "and want to gain " << values[1] << " shield" << '\n';
    std::cout << "His hp: " << values[2] << '\n';
    std::cout << "His defence: " << values[3] << '\n';
    if (!enemyEffects.empty()) {
        std::cout << "His effects:\n";
        for (auto& effect : enemyEffects) {
            std::cout << *effect.sayDescription() << '\n';
        }
    }
    std::cout << "Your Actions left: " << values[4] << '\n';
    std::cout << "Your hp left: " << values[5] << '\n';
    std::cout << "Your defence: " << values[6] << '\n';
    if (!playerEffects.empty()) {
        std::cout << "Your effects:\n";
        for (auto& effect : playerEffects) {
            std::cout << *effect.sayDescription() << '\n';
        }
    }
    std::cout << "Choose card to use:" << '\n';
    std::cout << 0 << " - Exit" << '\n';
}

void ConsoleInterface::showCard(int number, int damage, int defence, const std::string* description) {
    std::cout << number << " - deals " << damage << " damage to enemy and give ";
    std::cout << defence << " shield to you. " << *description << '\n';
}

int ConsoleInterface::read() {
    std::string command;
    std::cin >> command;
    int answer = -1;
    int count = 0;
    for (auto i : command) {
        if (i == ' ' || i == '\n') {
            continue;
        }
        ++count;
        int newNumber = static_cast<int>(i) - kAlphabetStart;
        if ((newNumber < 0) || (newNumber > 9)) {
            answer = -1;
            break;
        } else {
            if (answer == -1) {
                answer = 0;
            }
            answer = answer * 10 + newNumber;
        }
        if (count > kAdequateLength) {
            answer = -1;
            break;
        }
    }
    return answer;
}

void ConsoleInterface::showArtifact(int number, const std::string* description) {
    std::cout << number << " - use artifact: " << *description << '\n';
}