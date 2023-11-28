#include "Character.h"

Character::Character(){
    _row = 0;
    _column = 0;
    _ego = 0;
    _chances = 3;
}

void Character::characterInit(std::string name, int ego, int chances){
    _name = name;
    _ego = ego;
    _chances = chances;
}

