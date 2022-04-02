#include "Room.h"
#pragma once

class CombatRoom : public Room {
private:
    bool isEmpty = false;
    Difficulty difficulty;

public:
    RoomType sayType() override;
    bool sayIsEmpty() override;
    void setEmpty(bool value) override;
    void setDifficulty(Difficulty value) override;
    Difficulty sayDifficulty();
};
