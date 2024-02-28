#include "Inventory.h"
#include <iostream>


Inventory::Inventory() {}

vector<Item> Inventory::itemsInInv;

void Inventory::addItem(Item item, Character &character) {
    if(item.getTrait() != Entity::NOTRAIT)
        if (itemsInInv.size() == MAX){
            cout << endl;
            cout << "No more space in your reticule!" << endl;
            cout << endl;
            cout << "Would you like to exchange an item?" << endl;
            cout << "Yes or No" << endl;
            cout << endl;
            string secondChoice;
            cin >> secondChoice;
            if (secondChoice == "Yes" || secondChoice == "yes" || secondChoice == "y"){
                Inventory::showInventory();
                cout << endl;
                cout << "Which item would you like to exchange?" << endl;
                cout << "Choose [1], [2] or [3]" << endl;
                cout << endl;
                int positionChoice = 0;
                cin >> positionChoice;
                Inventory::tossItem(positionChoice, character);
                Inventory::addItem(item, character);
                character.traits[item.getTrait()] += item.getPower();
                Inventory::showInventory();
            } else if (secondChoice == "No" || secondChoice == "no" || secondChoice == "n") {
                cout << "The contents of you reticule remain unchanged." << endl;
            } else {
                cout << "I'll take it as a No." << endl;
            }
    } else {
            itemsInInv.push_back(item);
            character.traits[item.getTrait()] += item.getPower();
            cout << endl;
            cout << "You put " << item.getName() << " into your tiny reticule." << endl;
        }
    }




void Inventory::tossItem(int position, Character &character) {
    if (position >= 1 && position <= itemsInInv.size()) {
        Item tossedItem = itemsInInv[position - 1];
        cout << "You tossed " << tossedItem.getName() << " from your inventory." << endl;

        itemsInInv.erase(itemsInInv.begin() + (position - 1));
        character.traits[tossedItem.getTrait()] -= tossedItem.getPower();


    } else {
        cout << endl;
        cout << "Invalid inventory position." << endl;
    }
}

void Inventory::showInventory() {
    cout << endl;
    cout << "INVENTORY" << endl;

    if(itemsInInv.empty()){
        cout << "No items..." << endl;
    }

    for (int i=0;i<itemsInInv.size();i++) {
        cout << "[" << i + 1 << "] " << itemsInInv[i].getName() << " - " << itemsInInv[i].getTraitName() << " +" << itemsInInv[i].getPower() << std::endl;
    }
}

