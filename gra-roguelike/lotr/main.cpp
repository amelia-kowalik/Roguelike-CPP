#include <iostream>
#include <string>
#include <cstdlib>
#include "Game.h"
#include "BattleSystem.h"


int main() {
    Game game("level.txt");
    Character emma = Character(1,1,1,1,1,3);
    game.initDialogue();
    game.playGame();
    srand(time(NULL));

    //character.characterInit("Emma", 1, 3);


    /*int wygrane = 0;
    for(int i=0;i<1000;i++){
        Enemy enemy;
        bool wygrana = BattleSystem::seduction(character, enemy);
        if(wygrana)
            wygrane++;
    }
    cout << wygrane << "/" << 1000;*/
}
