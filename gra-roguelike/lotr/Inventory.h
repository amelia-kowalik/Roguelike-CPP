#ifndef LOTR_INVENTORY_H
#define LOTR_INVENTORY_H
#include <vector>
#include "Entity.h"
#include "Item.h"
#include "Character.h"
using namespace std;


class Inventory {
    static const int MAX = 3;
    static vector<Item> itemsInInv;
public:
    Inventory();
    static void addItem(Item item, Character &character);
    static void tossItem(int position, Character &character);
    static void showInventory();
};


#endif
