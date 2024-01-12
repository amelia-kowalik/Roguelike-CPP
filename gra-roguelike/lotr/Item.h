#ifndef LOTR_ITEM_H
#define LOTR_ITEM_H
#include <string>
#include <vector>
#include "Entity.h"
using namespace std;

class Item : public Entity {
    string name;
    Entity::TraitType trait;
    int power;
public:
    Item();
    static vector<Item> items;
    void makeItem(string name, Entity::TraitType trait, int power);
    Entity::TraitType getTrait();
    int getPower();
    string getName();
};


#endif
