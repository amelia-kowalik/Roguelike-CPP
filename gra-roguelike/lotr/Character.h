#ifndef LOTR_CHARACTER_H
#define LOTR_CHARACTER_H
#include <string>
#include <iostream>
#include "Entity.h"
#include "Item.h"

class Inventory;



using namespace std;

class Character : public Entity{
public:
    int _ego; //level
    int _chances; //lives
    Character();
    Character(int manipulation, int charisma, int intelligence, int charm, int ego, int chances);
    int getChances();
    void lostBattle();
    void wonBattle();
    void addPoints();
    void displayStats();
};


#endif
