#include "Level.h"
#include "Tile.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

Level::Level(){}

void Level::loadLevel(string fileName, Character &character) {
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
        default:
            system("PAUSE");
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
            character.setPos(targetRow, targetColumn);
            setTile(charaRow, charaColumn,'.');
            setTile(targetRow,targetColumn,'@');
            //inventory.addItem();
            break;
       // case Tile::ENEMY:
        default:
            break;
    }
}