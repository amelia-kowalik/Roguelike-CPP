#ifndef LOTR_CHARACTER_H
#define LOTR_CHARACTER_H
#include <string>
#include "Inventory.h"
#include "Entity.h"

using namespace std;

class Character : public Entity{
    int _ego; //level
    int _chances; //lives

public:
    Character();
    void characterInit(string name, int ego, int chances);
    /*void setPos(int row, int column);
    void getPos(int &row, int &column);*/
};


#endif
