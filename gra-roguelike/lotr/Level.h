#ifndef LOTR_LEVEL_H
#define LOTR_LEVEL_H
#include <vector>
#include <string>
#include "Character.h"
#include "Tile.h"
#include "Enemy.h"
#include "Entity.h"
#include "Inventory.h"
#include "BattleSystem.h"

using namespace std;

class Level {
    vector<vector<Tile>> levelData;
    vector<Enemy> enemies;
    vector<Item> itemsOnMap;
    void processMove(Character &character, int targetRow, int targetColumn);

public:
    Level();

    void loadLevel(string fileName, Character &character, int levelOflevel);
    void createLevel();
    void printLevel();
    void moveCharacter(char input, Character &character);
    char getTile(int row, int column);
    void setTile(int row, int column, char tile);
};


#endif
