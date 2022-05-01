#include "../Interface/InterfaceChooser.h"
#pragma once

class Client{
private:
    InterfaceChooser interface;

public:
    Client(InterfaceChooser newInterface);
    void newGame();
};