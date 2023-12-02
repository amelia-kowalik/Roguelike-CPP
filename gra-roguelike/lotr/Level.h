#ifndef LOTR_LEVEL_H
#define LOTR_LEVEL_H
#include <vector>
#include <string>
#include "Character.h"
#include "Tile.h"
#include "Enemy.h"
#include "Entity.h"
#include "BattleSystem.h"

using namespace std;

class Level {
    vector<vector<Tile>> levelData;
    vector<Enemy> enemies;
    void processMove(Character &character, int targetRow, int targetColumn);

public:
    Level();

    void loadLevel(string fileName, Character &character);
    void printLevel();
    void moveCharacter(char input, Character &character);
    char getTile(int row, int column);
    void setTile(int row, int column, char tile);
};


#endif
