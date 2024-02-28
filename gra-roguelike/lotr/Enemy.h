#ifndef LOTR_ENEMY_H
#define LOTR_ENEMY_H
#include "Character.h"
#include "Tile.h"
//#include "Level.h"
#include <vector>

class Enemy : public Entity {
public:
    Enemy();
    Enemy(int manipulation, int charisma, int intelligence, int charm);
    void makeAMove(vector<vector<Tile>> &mapData,vector<vector<Tile>> &levelData, Character &character);
    bool isFree = true;
    int weakness;
    void setWeakness();


};
#endif
