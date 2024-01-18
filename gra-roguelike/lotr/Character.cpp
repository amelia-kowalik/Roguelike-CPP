#include "Character.h"

Character::Character(){
    _row = 0;
    _column = 0;
}


Character::Character(int manipulation, int charisma, int intelligence, int charm, int ego, int chances) : Entity(
        manipulation, charisma, intelligence, charm), _ego(ego), _chances(chances) {}



void Character::lostBattle() {
    _chances--;
    cout << "Emma didn't manage to seduct this gentleman." << endl << "Chances left: " << _chances << endl;
}

void Character::wonBattle() {
    _ego++;
    cout << "Congratulations! Emma won this gentleman's heart! Her EGO grew!" << endl << "EGO points: " << _ego << endl;
}

void Character::displayStats() {
    cout << "CHANCES: " << _chances << endl;
    cout << "EGO: " << _ego << endl;
    cout << "TRAITS: " << endl;
    cout << "MANIPULATION [" << traits[MANIPULATION] << "]" << endl;
    cout << "CHARM [" << traits[CHARM] << "]" << endl;
    cout << "INTELLIGENCE [" << traits[INTELLIGENCE] << "]" << endl;
    cout << "CHARISMA [" << traits[CHARISMA] << "]" << endl;
    cout << endl;
}

void Character::addPoints(){
    cout << "You have " << _ego << " point(s) to spend! Choose the traits you want to make stronger: " << endl;
    cout << "1. MANIPULATION [" << traits[MANIPULATION] << "]" << endl;
    cout << "2. CHARM [" << traits[CHARM] << "]" << endl;
    cout << "3. INTELLIGENCE [" << traits[INTELLIGENCE] << "]" << endl;
    cout << "4. CHARISMA [" << traits[CHARISMA] << "]" << endl;

    int choice;
    cin >> choice;

    if(choice > 0 && choice <= 4){
        cout << "How many points would you like to add? " << endl << revTrait[choice-1] << " + ___ point(s) " << endl;
        int numberOfPoints;
        cin >> numberOfPoints;
        if(numberOfPoints <= _ego){
            traits[choice - 1] += numberOfPoints;
            cout << "Done!" << endl;
            _ego = 0;
            displayStats();
        }else{
            cout << "Your math is wrong, young lady! " << endl;
            cout << "How many points would you like to add? " << endl << revTrait[choice-1] << " + ___ point(s) " << endl;
        }

    } else {
        cout << "That's not an option!" << endl;
    }

}


/*void Character::addToInv(Item item) {
    Inventory::addItem(item);
    applyItemEffects(item);
}*/


void Character::displayEffects() {
    cout << "Item's have taken effect on your personality: " << endl;
    displayStats();
}
