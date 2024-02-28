#ifndef LOTR_GAME_H
#define LOTR_GAME_H
#include "Character.h"
#include "Level.h"
#include "Enemy.h"
#include "BattleSystem.h"
#include "Boss.h"
#include "Dialogue.h"
#include "Inventory.h"
#include "Item.h"
#include <string>
#include <iostream>

using namespace std;

class Game {
public:
    Character character;
    Level level;
    Game();
    void playGame();
    void characterMove();
    void enemiesMove();
    void initDialogue();
    void endScreen();
    void badEndScreen();
    void startScreen();
};


#endif
