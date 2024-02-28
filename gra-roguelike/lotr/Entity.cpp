#include "Entity.h"

Entity::Entity() {}

Entity::Entity(int manipulation, int charisma, int intelligence, int charm) {
    traits[MANIPULATION] = manipulation;
    traits[CHARM] = charisma;
    traits[INTELLIGENCE] = intelligence;
    traits[CHARISMA] = charm;
}


void Entity::setPos(int row, int column) {
    _row = row;
    _column = column;
}

void Entity::getPos(int &row, int &column) {
    row = _row;
    column = _column;
}

const char* Entity::revTrait[4] = {"MANIPULATION", "CHARM", "INTELLIGENCE" , "CHARISMA"};

string Entity::getTraitString(Entity::TraitType trait){
    if (trait >= 0 && trait < 4) {
        return revTrait[trait];
    }
    return "INVALID_TRAIT";
}


