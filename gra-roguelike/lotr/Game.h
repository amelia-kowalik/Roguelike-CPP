#ifndef LOTR_GAME_H
#define LOTR_GAME_H
#include "Character.h"
#include "Level.h"
#include <string>
#include <iostream>

using namespace std;

class Game {
    Character character;
    Level level;

public:
    Game(string levelFile);
    void playGame();
    void characterMove();
};


#endif
