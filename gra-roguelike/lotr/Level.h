#ifndef LOTR_LEVEL_H
#define LOTR_LEVEL_H
#include <vector>
#include <queue>
#include <string>
#include "Character.h"
#include "Tile.h"
#include "Enemy.h"
#include "Boss.h"
#include "Entity.h"
#include "Inventory.h"
#include "BattleSystem.h"
#include "MapTiles.h"
#include "Path.h"

using namespace std;

class Level {
public:
    vector<vector<Tile>> mapData;
    vector<vector<Tile>> levelData;
    vector<Item> itemsOnMap;
    vector<Enemy> enemies;
    int stage = 1;
    Level();

    void processMove(Character &character, int targetRow, int targetColumn);
    void readLevel(Character &character, int &stage, vector<vector<Tile>> &mapData);
    vector<vector<Tile>> createLevel();
    void changeLevel(Character &character, int &stage);
    void printLevel();
    void moveCharacter(char input, Character &character);
    char getTile(int row, int column);
    void setTile(int row, int column, char tile);
    void makeRoom(vector<vector<bool>> &mapa, int &positionOfX, int &positionOfY);
    void makeCorridors(vector<vector<bool>> &mapa, vector<int> &xPoints, vector<int> &yPoints);
    Path Pathway(vector<vector<bool>> &map, int startX, int startY, int endX, int endY);


};


#endif
