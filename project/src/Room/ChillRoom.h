#include "Room.h"
#pragma once

class ChillRoom : public Room {
private:
    bool isEmpty = false;

public:
    RoomType sayType() override;
    bool sayIsEmpty() override;
    void setEmpty(bool value) override;
    void setDifficulty(Difficulty value) override;
};
