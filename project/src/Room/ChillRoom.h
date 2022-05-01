#include "Room.h"
#pragma once

class ChillRoom : public Room {
private:
    bool isEmpty = false;

public:
    ~ChillRoom() override = default;
    RoomType sayType() override;
    bool sayIsEmpty() override;
    void setEmpty(bool value) override;
    void setDifficulty(Difficulty value) override;
    Difficulty sayDifficulty() override;
};
