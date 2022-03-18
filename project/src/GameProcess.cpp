#include "GameProcess.h"

extern bool timeToExit;

namespace Enemies{
    extern std::vector<AbstractEnemy*> allDeadEnemies;
}

GameProcess::GameProcess(Map& newMap, PlayerGameObject& newPlayer) : map(newMap), playerGameObject(newPlayer) {
    position = std::make_pair(0, 0);
}

void GameProcess::startChill() {
    int recover = std::min(kChillHpRecovery, kPlayerBaseHp - playerGameObject.hp);
    std::cout << "You rested and restored some hp(" << recover << ")" << '\n';
    playerGameObject.hp += recover;
}

Room* GameProcess::changeRoom(std::pair<int, int> direction) {
    position.first += direction.first;
    position.second += direction.second;
    return map.rooms[position.first][position.second];
}

void GameProcess::showMap() {
    for (int i = 0; i < map.rooms[0].size(); ++i) {
        for (int j = position.first - 1; j < static_cast<int>(map.rooms.size()); ++j) {
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
                    auto thisRoom = map.rooms[j][i];
                    if (thisRoom->sayIsEmpty()) {
                        std::cout << " . |";
                    } else {
                        if (thisRoom->sayType() == 1) {
                            std::cout << " " << 0 << " |";
                        }
                        if (thisRoom->sayType() == 2) {
                            auto room = dynamic_cast<CombatRoom *>(map.rooms[j][i]);
                            std::cout << " " << room->difficulty << " |";
                        }
                        if (thisRoom->sayType() == 0) {
                            std::cout << "end|";
                        }
                    }
                }
            }
        }
        std::cout <<'\n';
    }
}

Room* GameProcess::changingPosition() {
    bool ok = false;
    std::pair<int, int> direction;
    while (!ok && !timeToExit) {
        showMap();
        std::cout << "|1|2| |" << '\n';
        std::cout << "|I|3|4|" << '\n';
        std::cout << "|5|6| |" << '\n';
        std::cout << "Choose command:" << '\n';
        std::cout << "Exit - 0" << '\n';
        if (position.second > 0) {
            std::cout << "Go up - 1" << '\n';
            if (position.first + 1 < map.rooms.size()) {
                std::cout << "Go up-right - 2" << '\n';
            }
        }
        if (position.first + 1 < map.rooms.size()) {
            std::cout << "Go right - 3" << '\n';
            if (position.first + 3 < map.rooms.size()) {
                std::cout << "Go double right - 4" << '\n';
            }
        }
        if (position.second + 1 < map.rooms[position.first].size()) {
            std::cout << "Go down - 5" << '\n';
            if (position.first + 1 < map.rooms.size()) {
                std::cout << "Go down-right - 6" << '\n';
            }
        }
        std::string command;
        std::cin >> command;
        if (command == "0") {
            timeToExit = true;
            break;
        }
        if (command == "1" && position.second > 0) {
            ok = true;
            direction.first = 0;
            direction.second = -1;
        }
        if (command == "2" && position.second > 0) {
            ok = true;
            direction.first = 1;
            direction.second = -1;
        }
        if (command == "3" && position.first + 1 < map.rooms.size()) {
            ok = true;
            direction.first = 1;
            direction.second = 0;
        }
        if (command == "4" && position.first + 3 < map.rooms.size()) {
            ok = true;
            direction.first = 2;
            direction.second = 0;
        }
        if (command == "5" && position.second + 1 < map.rooms[position.first].size()) {
            ok = true;
            direction.first = 0;
            direction.second = 1;
        }
        if (command == "6" && position.second + 1 < map.rooms[position.first].size()) {
            ok = true;
            direction.first = 1;
            direction.second = 1;
        }
        if (!ok) {
            std::cout << "Unknown command" << '\n';
        }
    }
    return changeRoom(direction);
}

bool timeComp(const EffectType& first, const EffectType& second) {
    return first.time > second.time;
}

void GameProcess::startCombat(AbstractEnemy* enemy) {
    bool win = false;
    std::deque<Card*> cardDeque;
    auto liveEnemy = dynamic_cast<LiveObject*>(enemy);
    {
        auto rng = std::default_random_engine{};
        std::shuffle(playerGameObject.cardDeque.begin(), playerGameObject.cardDeque.end(), rng);
        cardDeque = playerGameObject.cardDeque;
    }
    int actionAmount;
    int cardPerTurnAmount;
    while (!win && !timeToExit) {
        if (playerGameObject.hp <= 0) {
            std::cout << "You died" << '\n';
            std::cout << "Print something to exit" << '\n';
            std::string command;
            std::cin >> command;
            timeToExit = true;
            break;
        }
        for (int i = 0; i < playerGameObject.currentEffects.size(); ++i) {
            --playerGameObject.currentEffects[i].time;
        }
        std::sort(playerGameObject.currentEffects.begin(), playerGameObject.currentEffects.end(), timeComp);
        for (int i = static_cast<int>(playerGameObject.currentEffects.size()) - 1; i >= 0; --i) {
            if (playerGameObject.currentEffects[i].time > 0) {
                break;
            }
            playerGameObject.currentEffects.pop_back();
        }
        actionAmount = playerGameObject.actionAmount;
        cardPerTurnAmount = playerGameObject.cardPerTurnAmount;
        for (int i = 0; i < playerGameObject.currentEffects.size(); ++i) {
            actionAmount += playerGameObject.currentEffects[i].actionAmountInfluence;
            cardPerTurnAmount += playerGameObject.currentEffects[i].cardAmountInfluence;
        }
        std::vector<Card*> hand;
        std::vector<bool> used(cardPerTurnAmount, false);
        for (int i = 0; i < cardPerTurnAmount; ++i) {
            if (cardDeque.size() == 0) {
                auto rng = std::default_random_engine {};
                std::shuffle(playerGameObject.cardDeque.begin(), playerGameObject.cardDeque.end(), rng);
                cardDeque = playerGameObject.cardDeque;
            }
            hand.push_back(cardDeque.front());
            cardDeque.pop_front();
        }
        actionAmount = playerGameObject.actionAmount;
        std::pair<int, int> damDef = enemy->nextAttack(playerGameObject);
        playerGameObject.defence /= kDefenceDecreaseScalePerTurn;
        while (actionAmount > 0 && !timeToExit && !win) {
            damDef = enemy->recalculate(playerGameObject);
            std::cout << '\n' << "Enemy want to deal " << damDef.first << " damage to you ";
            std::cout << "and want to gain " << damDef.second << " shield" << '\n';
            std::cout << "His hp: " << liveEnemy->hp << '\n';
            std::cout << "His defence: " << liveEnemy->defence << '\n';
            std::cout << "Your Actions left: " << actionAmount << '\n';
            std::cout << "Your hp left: " << playerGameObject.hp << '\n';
            std::cout << "Your defence: " << playerGameObject.defence << '\n';
            std::cout << "Choose card to use:" << '\n';
            std::cout << 0 << " - Exit" << '\n';
            for (int i = 0; i < hand.size(); ++i) {
                if (!used[i]) {
                    std::pair<int, int> cardDamDef = hand[i]->realDamDef(&playerGameObject);
                    std::cout << i + 1 << " - deals " << cardDamDef.first << " damage to enemy and give ";
                    std::cout << cardDamDef.second << " shield to you." << '\n' << hand[i]->sayDescription(); //<< '\n';
                }
            }
            int command;
            bool ok = false;
            while (!ok) {
                std::cin >> command;
                if (command == 0) {
                    ok = true;
                    timeToExit = true;
                }
                for (int i = 0; i < hand.size(); ++i) {
                    if (command == i + 1 && !used[command - 1]) {
                        ok = true;
                        used[command - 1] = true;
                        hand[i]->use(liveEnemy, &playerGameObject);
                    }
                    //hand.erase(hand.begin() + i);
                }
                if (!ok) {
                    std::cout << "Unknown Command, print 0 to Exit or number to use card" << '\n';
                } else {
                    --actionAmount;
                }
            }
            if (dynamic_cast<LiveObject*>(enemy)->hp <= 0) {
                playerGameObject.currentEffects.clear();
                win = true;
                std::cout << "You killed enemy. You get reward - ";
            }
        }
        if (!win) {
            for (int i = 0; i < liveEnemy->currentEffects.size(); ++i) {
                --liveEnemy->currentEffects[i].time;
            }
            std::sort(liveEnemy->currentEffects.begin(), liveEnemy->currentEffects.end(), timeComp);
            for (int i = static_cast<int>(liveEnemy->currentEffects.size()) - 1; i >= 0; --i) {
                if (liveEnemy->currentEffects[i].time > 0) {
                    break;
                }
                liveEnemy->currentEffects.pop_back();
            }
            liveEnemy->defence /= kDefenceDecreaseScalePerTurn;
            enemy->attack(playerGameObject);
        }
    }
    Enemies::allDeadEnemies.push_back(enemy);
    if (win) {
        playerGameObject.currentEffects.clear();
        playerGameObject.defence = 0;
        {
            auto tempEnemy = dynamic_cast<WeakEnemy *>(enemy);
            if (tempEnemy != nullptr) {
                std::pair<int, int> damDef = tempEnemy->reward->realDamDef(&playerGameObject);
                std::cout << "common card: " << '\n';
                std::cout << tempEnemy->reward->sayDescription();
                std::cout << " Deals " << damDef.first << " damage and give " << damDef.second << " shield" << '\n';
                playerGameObject.cardDeque.push_back(tempEnemy->reward);
            }
        }
        {
            auto tempEnemy = dynamic_cast<CommonEnemy *>(enemy);
            if (tempEnemy != nullptr) {
                std::pair<int, int> damDef = tempEnemy->reward->realDamDef(&playerGameObject);
                std::cout << "strong card: " << '\n';
                std::cout << tempEnemy->reward->sayDescription();
                std::cout << " Deals " << damDef.first << " damage and give " << damDef.second << " shield" << '\n';
                playerGameObject.cardDeque.push_back(tempEnemy->reward);
            }
        }
        {
            auto tempEnemy = dynamic_cast<StrongEnemy *>(enemy);
            if (tempEnemy != nullptr) {
                std::cout << "strange useless artifact" << '\n';
                playerGameObject.artifacts.push_back(tempEnemy->reward);
            }
        }
    }
}