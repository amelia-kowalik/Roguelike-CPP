#ifndef LOTR_INVENTORY_H
#define LOTR_INVENTORY_H
#include "Item.h"
#include <vector>


class Inventory {
    vector<Item> items;
public:
    Inventory();
    void addItem(Item item);
    void tossItem(int position);
};


#endif
