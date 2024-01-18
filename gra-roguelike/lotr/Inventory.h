#ifndef LOTR_INVENTORY_H
#define LOTR_INVENTORY_H
#include <vector>
#include "Entity.h"
#include "Item.h"
class Character;
using namespace std;


class Inventory {
    static const int MAX = 3;
    static vector<Item> itemsInInv;
public:
    Inventory();
    static void addItem(Item item);
    static void tossItem(int position);
    static void showInventory();
   /* void applyItemEffects(Item item, Character &character);
    void removeItemEffects(Item item, Character &character);*/
};


#endif
