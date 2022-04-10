#include "Room.h"
#pragma once

class EndRoom : public Room {
public:
    RoomType sayType() override;
    bool sayIsEmpty() override;
    void setEmpty(bool value) override;
    void setDifficulty(Difficulty value) override;
    Difficulty sayDifficulty() override;
};
