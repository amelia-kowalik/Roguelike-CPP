#include "Inventory.h"
#include "Character.h"
#include <iostream>


Inventory::Inventory() {}

vector<Item> Inventory::itemsInInv;

void Inventory::addItem(Item item) {
    // wyswietlona nazwa item.GetName() i czy chcesz item? if()
    if (itemsInInv.size() == MAX){
        cout << "NO MORE SLOTS LEFT!" << endl;
        //ktory item wyrzucic
    } else
    itemsInInv.push_back(item);
    cout << "AN ITEM HAS BEEN ADDED TO THE INVENTORY" << endl;
    //character.Trait[item.getTrait()] += item.getPower();
}

void Inventory::tossItem(int position) {
    if (position >= 0 && position < itemsInInv.size()){
        itemsInInv.erase(itemsInInv.begin()+(position-1));
        cout << "YOU TOSSED " << itemsInInv[position].getName() << " FROM YOUR INVENTORY" << endl;
    } else {
        cout << "INVALID INVENTORY POSITION" << endl;
    }
}

void Inventory::showInventory() {
    cout << endl;
    cout << "INVENTORY" << endl;

    for (int i=0;i<itemsInInv.size();i++) {
        cout << "- " << itemsInInv[i].getName() << std::endl;
    }
}