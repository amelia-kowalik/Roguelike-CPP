#include <iostream>
#include <string>
#include "Game.h"


int main() {
    Game game("level.txt");
   /* Enemy enemy;
    game.level.battle(game.character, enemy);*/
    game.playGame();
}
