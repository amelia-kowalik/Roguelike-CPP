#include "Level.h"
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <windows.h>
using namespace std;


Level::Level(){}

void Level::createLevel() {
    cout << "Dziala" << endl;

    int x = 8;
    int y = 9;
    vector<vector<bool>> visited(x, vector<bool>(y, false));

    //int numberOfRooms = rand() % 5 + 2;
    int numberOfRooms = 1;


    cout << numberOfRooms << endl;
    for(int i=0;i< numberOfRooms;i++){
        int x_rand = rand() % (x - 1) + 1;
        int y_rand = rand() % (y - 1) + 1;

        visited[x_rand][ y_rand] = true;

        //int roomX = rand() % 7 + 1;
        int roomX = 4;
        int roomY = rand() % 8 + 1;

        // wypelnainie mapy na x
        if(roomX == 1){
            visited[x_rand][ y_rand] = true;
        }
        else{
             int widthDivided = roomX / 2;
             for(int j=x_rand; j<=(x_rand + widthDivided) - 1; j++){
                 if(j == x-1){
                     break;
                 } else {
                     visited[j][y_rand] = true;
                 }
             }
        }
    }

    for(int i=y - 1; i>=0; i--){
        for(int j=0; j<x; j++){
            //SetConsoleTextAttribute(hOut, BACKGROUND_RED);
            // pamietaj aby wyzerowac od razu po wypisaniu
            if(visited[i][j]){
                cout << "O";
            }
            else{
                cout << "#";
            }
        }
        cout << endl;
    }

    cout << "!!";
}

void Level::loadLevel(string fileName, Character &character, int levelOflevel) {
    //loading the level
    ifstream file;

    file.open(fileName);
    if (file.fail()) {
        perror(fileName.c_str());
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        vector<Tile> row;
        for(int i=0; i<line.size(); i++){
            char tileChar = line[i];
            Tile tile(tileChar);
            row.push_back(tile);

            if(tile.getTileType() == Tile::CHARACTER){
                character.setPos(levelData.size(),i);
            }


            if(tile.getTileType() == Tile::ENEMY){
                Enemy en;
                switch(levelOflevel){
                    case 1:
                        en = Enemy(rand() % 2 + 1,rand() % 2 + 1,rand() % 2 + 1,rand() % 2 + 1);
                        break;
                    case 2:
                        en = Enemy(rand() % 3 + 1,rand() % 3 + 1,rand() % 3 + 1,rand() % 3 + 1);
                        break;
                    case 3:
                        en = Enemy(rand() % 3 + 1,rand() % 3 + 1,rand() % 3 + 1,rand() % 3 + 1);
                        break;
                    case 4:
                        en = Enemy(rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1);
                        break;
                    case 5:
                        en = Enemy(rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1,rand() % 5 + 1);
                        break;
                }
                en.setPos(levelData.size(),i);
                enemies.push_back(en);
            }

            if(tile.getTileType() == Tile::ITEM){
                Item it;

                int randRarity = rand() % 100 + 1;
                if(randRarity <= 50){
                    int randItem = rand() % 3 + 1;
                    switch(randItem){
                        case 1:
                            it.makeItem("Gloves", Entity::CHARM, 1);
                            break;
                        case 2:
                            it.makeItem("Narcissus", Entity::MANIPULATION, 1);
                            break;
                        case 3:
                            it.makeItem("Handkerchief", Entity::CHARISMA, 1);
                            break;
                    }
                }
                else if(randRarity <= 70){
                    int randItem = rand() % 3 + 1;
                    switch(randItem){
                        case 1:
                            it.makeItem("Blush", Entity::CHARM, 2);
                            break;
                        case 2:
                            it.makeItem("Emma's Drawings", Entity::INTELLIGENCE, 2);
                            break;
                        case 3:
                            it.makeItem("Shawl", Entity::CHARM, 2);
                            break;
                    }
                }
                else if(randRarity <= 80){
                    int randItem = rand() % 3 + 1;
                    switch(randItem){
                        case 1:
                            it.makeItem("Frances Burney's novel", Entity::INTELLIGENCE, 3);
                            break;
                        case 2:
                            it.makeItem("Fan", Entity::CHARISMA, 3);
                            break;
                    }
                }
                else if(randRarity <= 98){
                    it.makeItem("Perfume", Entity::MANIPULATION, 4);
                }
                else {
                    it.makeItem("Hibiscus tea", Entity::NOTRAIT, 2);
                }
                it.setPos(levelData.size(),i);
                itemsOnMap.push_back(it);
            }

        }
        levelData.push_back(row);
    }
    file.close();

}


//printing map in terminal
void Level::printLevel(){
    //printf("%s", std::string(100, '\n').c_str());

    for(int i=0; i<levelData.size(); i++){
        for(int j=0; j<levelData[i].size(); j++){
            //SetConsoleTextAttribute(hOut, BACKGROUND_RED);
            // pamietaj aby wyzerowac od razu po wypisaniu
            cout << levelData[i][j].getTileChar();
        }
        cout << endl;
    }
    cout << endl;
}


void Level::moveCharacter(char input, Character &character) {
    int charaRow;
    int charaColumn;

    character.getPos(charaRow, charaColumn);



    switch (input) {
        case 'w':
            processMove(character, charaRow-1, charaColumn);
            break;
        case 's':
            processMove(character, charaRow+1, charaColumn);
            break;
        case 'a':
            processMove(character, charaRow, charaColumn-1);
            break;
        case 'd':
            processMove(character, charaRow, charaColumn+1);
            break;
        case 'f':
            character.displayStats();
            break;
        case 'r':
            character.addPoints();
            break;
        case 'q':
            Inventory::showInventory();
            break;
        //default:
            //system("PAUSE");
    }
}

char Level::getTile(int row, int column){
    return levelData[row][column].getTileChar();
}

void Level::setTile(int row, int column, char tile){
    levelData[row][column] = Tile(tile);
}

void Level::processMove(Character &character, int targetRow, int targetColumn) {
    int charaRow;
    int charaColumn;
    character.getPos(charaRow, charaColumn);

    Tile moveToTile = getTile(targetRow, targetColumn);

    switch (moveToTile.getTileType()) {
        case Tile::WALL://running into a wall
        character.setPos(charaRow, charaColumn);
        cout << "THAT'S A WALL !!!" << endl;
            break;
        case Tile::FLOOR://walking on the floor
            character.setPos(targetRow, targetColumn); //target tile
            setTile(charaRow, charaColumn,'.'); //old placement changes to 'floor'
            setTile(targetRow,targetColumn,'@'); //target placement changes to 'character'
            break;
        case Tile::ITEM:
            int itemIndex;
            for(size_t i=0; i<itemsOnMap.size(); i++){
                int itemRow, itemColumn;
                itemsOnMap[i].getPos(itemRow,itemColumn);

                if(itemRow == targetRow && itemColumn == targetColumn){
                    itemIndex = i;
                }

            }
            if(itemIndex != -1) {
                /*if(itemsOnMap[itemIndex].getName() == "Hibiscus Tea"){
                    //uzyj od razu
                }*/
                cout << "You found " << itemsOnMap[itemIndex].getName() << " just laying there. Would you like to take it?" << endl;
                cout << "Yes or No" << endl;
                string choice;
                cin >> choice;
                if (choice == "Yes" || choice == "yes") {
                    character.setPos(targetRow, targetColumn);
                    setTile(charaRow, charaColumn, '.');
                    setTile(targetRow, targetColumn, '@');
                    //character.addToInv(itemsOnMap[itemIndex]);
                    itemsOnMap.erase(itemsOnMap.begin() + itemIndex);
                    character.displayEffects();
                }
            }
            break;

            case Tile::ENEMY:
                for (size_t i = 0; i < enemies.size(); i++) {
                int enemyRow, enemyColumn;
                enemies[i].getPos(enemyRow, enemyColumn);

                if (enemyRow == targetRow && enemyColumn == targetColumn) {
                    if(!enemies[i].isFree){
                        cout << "This gentleman is already yours." << endl;
                        character.setPos(charaRow, charaColumn);
                    } else {
                        BattleSystem::seduction(character, enemies[i]);
                        break;
                    }
                }
            }
            break;
        default:
            break;
    }
}