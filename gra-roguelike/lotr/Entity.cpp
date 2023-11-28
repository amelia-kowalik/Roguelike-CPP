#include "Entity.h"

Entity::Entity() {}

Entity::Entity(int manipulation, int charisma, int intelligence, int charm) {
    manipulation = manipulation;
    charisma = charisma;
    intelligence;
    charm;
}


void Entity::setPos(int row, int column) {
    _row = row;
    _column = column;
}

void Entity::getPos(int &row, int &column) {
    row = _row;
    column = _column;
}




