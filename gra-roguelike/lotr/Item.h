#ifndef LOTR_ITEM_H
#define LOTR_ITEM_H
#include <string>
#include <vector>
#include "Entity.h"
using namespace std;

class Item : public Entity {
    string _name;
    Entity::TraitType _trait;
    int _power;
public:
    Item();
    static vector<Item> items;
    void makeItem(string name, Entity::TraitType trait, int power);
    string getName();
    string getTraitName();
    int getPower();
};


#endif
