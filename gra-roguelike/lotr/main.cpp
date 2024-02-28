#include <iostream>
#include <string>
#include <cstdlib>
#include "Game.h"
#include <ctime>


int main() {
    srand(time(NULL));


    Game game;
    game.initDialogue();
    game.playGame();

}
