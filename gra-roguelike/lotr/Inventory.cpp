#include "Inventory.h"
#include <iostream>
using namespace std;

Inventory::Inventory() {}

void Inventory::addItem(Item item) {
    if (items.size() == 3){
        cout << "NO MORE SLOTS LEFT!" << endl;
    } else
    items.push_back(item);
    cout << "AN ITEM HAS BEEN ADDED TO THE INVENTORY" << endl;
}

void Inventory::tossItem(int position) {
    if (position <= 3){
        items.erase(items.begin()+(position-1));
    }
}