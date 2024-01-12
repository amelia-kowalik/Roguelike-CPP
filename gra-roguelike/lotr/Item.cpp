#include "Item.h"

Item::Item() : Entity() {}

void Item::makeItem(std::string _name, Entity::TraitType _trait, int _power) {
    name = _name;
    trait = _trait;
    power = _power;
}

//void Item::pickUpItem() {}

string Item::getName() {
    return name;
}