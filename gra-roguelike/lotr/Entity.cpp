#include "Entity.h"

Entity::Entity() {}

Entity::Entity(int manipulation, int charisma, int intelligence, int charm) {
    Trait[MANIPULATION] = manipulation;
    Trait[CHARM] = charisma;
    Trait[INTELLIGENCE] = intelligence;
    Trait[CHARISMA] = charm;
}


void Entity::setPos(int row, int column) {
    _row = row;
    _column = column;
}

void Entity::getPos(int &row, int &column) {
    row = _row;
    column = _column;
}




