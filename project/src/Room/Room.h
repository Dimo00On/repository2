#pragma once

enum class RoomType {End = 0, Chill, Combat};
enum class Difficulty {None = 0, Easy, Normal, Hard};
class Room{
public:
    virtual ~Room() = default;
    virtual RoomType sayType() = 0;
    virtual bool sayIsEmpty() = 0;
    virtual void setEmpty(bool value) = 0;
    virtual void setDifficulty(Difficulty value) = 0;
};
