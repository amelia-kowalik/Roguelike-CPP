#ifndef LOTR_INVENTORY_H
#define LOTR_INVENTORY_H
#include "Item.h"
#include "Character.h"
#include "Entity.h"
#include <vector>
using namespace std;


class Inventory {
    static const int MAX = 3;
    static vector<Item> itemsInInv;
public:
    Inventory();
    static void addItem(Item item);
    static void tossItem(int position);
    static void showInventory();
};


#endif
