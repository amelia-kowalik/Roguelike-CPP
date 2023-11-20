#include "Character.h"

Character::Character(){
    _row = 0;
    _column = 0;
}

void Character::characterInit(std::string name, int ego, int chances){
    _name = name;
    _ego = ego;
    _chances = chances;
}

void Character::setPos(int row, int column) {
    _row = row;
    _column = column;
}

void Character::getPos(int &row, int &column) {
    row = _row;
    column = _column;
}