#include "Inventory.h"
#include <iostream>


Inventory::Inventory() {}

vector<Item> Inventory::itemsInInv;

void Inventory::addItem(Item item) {
    /*cout << "You found " << item.getName() << " just laying there. Would you like to take it?" << endl;
    cout << "Yes or No" << endl;
    string choice;
    cin >> choice;
    if(choice == "Yes" || choice == "yes"){*/
        if (itemsInInv.size() == MAX){
            cout << endl;
            cout << "No more space in your reticule!" << endl;
            cout << endl;
            cout << "Would you like to exchange an item?" << endl;
            cout << "Yes or No" << endl;
            cout << endl;
            string secondChoice;
            cin >> secondChoice;
            if (secondChoice == "Yes" || secondChoice == "yes"){
                Inventory::showInventory();
                cout << endl;
                cout << "Which item would you like to exchange?" << endl;
                cout << "Choose [1], [2] or [3]" << endl;
                cout << endl;
                int positionChoice = 0;
                cin >> positionChoice;
                Inventory::tossItem(positionChoice);
                Inventory::addItem(item);
                Inventory::showInventory();
            } else if (secondChoice == "No" || secondChoice == "no") {
                cout << "The contents of you reticule remain unchanged." << endl;
            } else {
                cout << "I'll take it as a No." << endl;
            }
    } else {
            itemsInInv.push_back(item);
            cout << endl;
            cout << "You put " << item.getName() << " into your tiny reticule." << endl;
        }
    }

    //character.traits[item.getTrait()] += item.getPower();


void Inventory::tossItem(int position) {
    if (position >= 1 && position <= itemsInInv.size()){
        cout << "You tossed " << itemsInInv[position - 1].getName() << " from your reticule." << endl;
        //character.removeItemEffects(itemsInInv[position-1]);
        itemsInInv.erase(itemsInInv.begin()+(position - 1));

        cout << endl;

    } else {
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

