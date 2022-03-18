#pragma once

struct Room{
    virtual ~Room() = default;
    virtual int sayType() = 0;
    virtual bool sayIsEmpty() = 0;
};

struct EndRoom : Room {
    int sayType() override;
    bool sayIsEmpty() override;
};

struct ChillRoom : Room {
    bool isEmpty = false;

    int sayType() override;
    bool sayIsEmpty() override;
};

struct CombatRoom : Room {
    bool isEmpty = false;
    int difficulty;

    int sayType() override;
    bool sayIsEmpty() override;
};
