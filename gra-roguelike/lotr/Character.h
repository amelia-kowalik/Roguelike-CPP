#ifndef LOTR_CHARACTER_H
#define LOTR_CHARACTER_H
#include <string>
#include "Inventory.h"

using namespace std;

class Character {
    string _name;
    int _ego; //level
    int _chances; //lives
    int _row, _column; //position

public:
    Character();
    void characterInit(string name, int ego, int chances);
    void setPos(int row, int column);
    void getPos(int &row, int &column);
};


#endif
