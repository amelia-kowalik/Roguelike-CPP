#ifndef LOTR_GAME_H
#define LOTR_GAME_H
#include "Character.h"
#include "Level.h"
#include "Enemy.h"
#include <string>
#include <iostream>

using namespace std;

class Game {



public:
    Character character;
    Level level;
    Game(string levelFile);
    void playGame();
    void characterMove();
};


#endif
