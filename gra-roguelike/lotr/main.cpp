#include <iostream>
#include <string>
#include <cstdlib>
#include "Game.h"
#include <ctime>


int main() {
    srand(time(NULL));



    Game game("level.txt");
    game.initDialogue();
    game.playGame();




    /*int wygrane = 0;
    for(int i=0;i<1000;i++){
        Enemy enemy;
        bool wygrana = BattleSystem::seduction(character, enemy);
        if(wygrana)
            wygrane++;
    }
    cout << wygrane << "/" << 1000;*/
}
