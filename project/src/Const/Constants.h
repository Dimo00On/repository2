#pragma once

enum class Interface{Console = 0, Graphic, Network};
const Interface kChosenInterface = Interface::Console;
const int kStrongHp = 30;
const int kCommonHp = 20;
const int kPlayerBaseHp = 100;
const int kWeakHp = 10;
const int kBaseEffectDuration = 2;
const int kBaseActionAmount = 3;
const int kBaseCardPerTurnAmount = 6;
const int kStartCardAmount = 4;
const int kRandomLimit = 100;
const int kChillRandomLimit = 25;
const int kCommonFightRandomLimit = 75;
const int kBaseMapSize1 = 5;
const int kBaseMapSize2 = 7;
const int kChillHpRecovery = 30;
const int kDefenceDecreaseScalePerTurn = 3;
const int kAlphabetStart = 48;
const int kAdequateLength = 7;