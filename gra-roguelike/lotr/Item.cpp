#include "Item.h"

Item::Item() : Entity() {}

void Item::makeItem(std::string name, Entity::TraitType trait, int power) {
    _name = name;
    _trait = trait;
    _power = power;
}


string Item::getName() {
    return _name;
}

string Item::getTraitName(){
    return Entity::getTraitString(_trait);
}

int Item::getPower() {
    return _power;
}