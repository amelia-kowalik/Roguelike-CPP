#include "Entity.h"

Entity::Entity() {}

Entity::Entity(int manipulation, int charisma, int intelligence, int charm) {
    Traits[0] = manipulation;
    Traits[1] = charisma;
    Traits[2] = intelligence;
    Traits[3] = charm;
}


void Entity::setPos(int row, int column) {
    _row = row;
    _column = column;
}

void Entity::getPos(int &row, int &column) {
    row = _row;
    column = _column;
}




