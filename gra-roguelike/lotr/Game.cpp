#include "Game.h"
#include <conio.h>

Game::Game(string levelFile){

    character.characterInit("Emma", 1, 3);

    level.loadLevel(levelFile, character);
    level.printLevel();

    system("PAUSE");
}

void Game::playGame(){
    bool isDone = false;
    while (isDone == false){
        level.printLevel();
        characterMove();
    }

}

void Game::characterMove(){
    char input='d';
    //input = getch();
    cin>>input;
    //cout<<"test"<<endl;
    level.moveCharacter(input, character);
}