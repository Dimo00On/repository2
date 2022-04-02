#include "src/Game/Client.h"
#include "src/Card/Card.h"
#include "src/AbstractFactory/AbstractFactory.h"
#include <iostream>
#include <ctime>

bool timeToExit = false;

void createArtifacts();
void createEnemies();
void createCards();
void preCalc();
void clear();
