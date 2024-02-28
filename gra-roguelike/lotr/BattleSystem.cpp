#include "BattleSystem.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void BattleSystem::seduction(Character &emma, Enemy &admirer) {
    cout << "Would you like to seduct this gentleman" << endl;
    cout << "Yes or No?" << endl;
    string choice;
    cin >> choice;
    cout << endl;

    if (choice == "Yes" || choice == "yes" || choice == "y") {
        cout << "ADMIRER" << endl;
        cout << Dialogue::getRandomStartingAdmirerDialogue(admirer.weakness) << endl;
        int admirerHP = 33;
        int emmaHP = 33;

        while (admirerHP > 0 || emmaHP > 0) {
            vector<Dialogue::DialogueLine> options;
            options.push_back(Dialogue::getRandomCharacterLine());
            options.push_back(Dialogue::getRandomCharacterLine());

            int lineChoice;
            cout << endl;
            cout << "EMMA" << endl;
            cout << "1. " << options[0].line << " " << "(" << Entity::getTraitString(static_cast<Entity::TraitType>(options[0].trait)) << ")" << endl;
            cout << "2. " << options[1].line << " " << "(" << Entity::getTraitString(static_cast<Entity::TraitType>(options[1].trait)) << ")" << endl;
            cout << "Choose one response:  1 or 2" << endl;
            cin >> lineChoice;




            //wybrana opcja 1
            if (lineChoice == 1) {
                int damageEmma;
                int damageAdmirer;
                int admirerDiceRoll = rand() % 3 + 1;
                int diceRoll = rand() % 3 + 1;


                //jesli gracz wybrał dialog zgodny ze słabością admirera
                if (options[0].trait == admirer.weakness) {
                    damageEmma = (emma.traits[options[0].trait] + 3) * diceRoll; //+punkty z przedmiotów
                    damageAdmirer = admirer.weakness * admirerDiceRoll;
                    //jesli obrażenia, które zada gracz są mniejsze niż admirera
                    if (damageEmma < damageAdmirer) {
                        emmaHP = emmaHP - damageAdmirer;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                        cout << "Oh no! This gentleman's " << Entity::getTraitString(static_cast<Entity::TraitType>(options[0].trait)) << " powers are stronger than yours!" << endl;
                        cout << endl;
                        cout << "Emma's HP: " << emmaHP << endl;
                        cout << "Admirer's HP: " << admirerHP << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                    } else {
                        admirerHP = admirerHP - damageEmma;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                        cout << "Bullseye! You really know how to talk to people!" << endl;
                        cout << endl;
                        cout << "Emma's HP: " << emmaHP << endl;
                        cout << "Admirer's HP: " << admirerHP << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                    }

                    //jesli gracz wybrał dialog NIEZGODNY ze słabością
                } else {
                    damageEmma = emma.traits[options[0].trait] * diceRoll;
                    damageAdmirer = admirer.traits[options[0].trait] * admirerDiceRoll;
                    //jesli obrażenia, które zada gracz są mniejsze niż admirera
                    if (damageEmma < damageAdmirer) {
                        emmaHP = emmaHP - damageAdmirer;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                        cout << "Oh no! This gentleman's " << Entity::getTraitString(static_cast<Entity::TraitType>(options[0].trait)) << " powers are stronger than yours!" << endl;
                        cout << endl;
                        cout << "Emma's HP: " << emmaHP << endl;
                        cout << "Admirer's HP: " << admirerHP << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                    } else {
                        admirerHP = admirerHP - damageEmma;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                        cout << "Good job! You're really good at talking." << endl;
                        cout << endl;
                        cout << "Emma's HP: " << emmaHP << endl;
                        cout << "Admirer's HP: " << admirerHP << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                    }
                }

                if(emmaHP <= 0){
                    cout << Dialogue::getRandomNegativeAdmirerResponse() << endl;
                    emma.lostBattle();
                    break;
                }

                if(admirerHP <= 0){
                    admirer.isFree = false;
                    cout << "ADMIRER:" << Dialogue::getRandomPositiveAdmirerResponse() << endl;
                    emma.wonBattle();
                    break;
                }



            } else if (lineChoice == 2) {
                int damageEmma;
                int damageAdmirer;
                int admirerDiceRoll = rand() % 3 + 1;
                int diceRoll = rand() % 3 + 1;

                //jesli gracz wybrał dialog zgodny ze słabością admirera
                if (options[1].trait == admirer.weakness) {
                    damageEmma = (emma.traits[options[1].trait] + 3) * diceRoll; //+punkty z przedmiotów
                    damageAdmirer = admirer.weakness * admirerDiceRoll;

                    //jesli obrażenia, które zada gracz są mniejsze niż admirera
                    if (damageEmma < damageAdmirer) {
                        emmaHP = emmaHP - damageAdmirer;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                        cout << "Oh no! This gentleman's " << Entity::getTraitString(static_cast<Entity::TraitType>(options[1].trait)) << " powers are stronger than yours!"
                             << endl;
                        cout << endl;
                        cout << "Emma's HP: " << emmaHP << endl;
                        cout << "Admirer's HP: " << admirerHP << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                    } else {
                        admirerHP = admirerHP - damageEmma;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                        cout << "Bullseye! You really know how to talk to people!" << endl;
                        cout << endl;
                        cout << "Emma's HP: " << emmaHP << endl;
                        cout << "Admirer's HP: " << admirerHP << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;


                    }
                    } else { //jesli gracz wybrał dialog NIEZGODNY ze słabością
                    damageEmma = emma.traits[options[1].trait] * diceRoll;
                    damageAdmirer = admirer.traits[options[1].trait] * admirerDiceRoll;

                    //jesli obrażenia, które zada gracz są mniejsze niż admirera
                    if (damageEmma < damageAdmirer) {
                        emmaHP = emmaHP - damageAdmirer;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                        cout << "Oh no! This gentleman's " << Entity::getTraitString(static_cast<Entity::TraitType>(options[1].trait)) << " powers are stronger than yours!" << endl;
                        cout << endl;
                        cout << "Emma's HP: " << emmaHP << endl;
                        cout << "Admirer's HP: " << admirerHP << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                    } else {
                        admirerHP = admirerHP - damageEmma;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                        cout << "Good job! You're really good at talking." << endl;
                        cout << endl;
                        cout << "Emma's HP: " << emmaHP << endl;
                        cout << "Admirer's HP: " << admirerHP << endl;
                        cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<< endl;
                    }
                }
                if(emmaHP <= 0){
                    cout << endl;
                    cout << Dialogue::getRandomNegativeAdmirerResponse() << endl;
                    cout << endl;
                    emma.lostBattle();
                    break;
                }

                if(admirerHP <= 0){
                    admirer.isFree = false;
                    cout << endl;
                    cout << "ADMIRER:" << Dialogue::getRandomPositiveAdmirerResponse() << endl;
                    cout << endl;
                    emma.wonBattle();
                    break;
                }

            } else {
                cout << "It's not an option!" << endl;
            }
            cout << endl;
            cout << "ADMIRER" << endl;
            cout << Dialogue::getRandomNegativeAdmirerResponse() << endl;
        }

    }
}

Boss BattleSystem::prince = Boss(20,20,20,20,false);

void BattleSystem::megaSeduction(Character &emma){
    cout << "This is him, The Prince, the one you really want. The real test of your seductive abilities!" << endl;
    cout << endl;
    cout << "Would you like to try your luck? You have no choice..." << endl;
    string choice;
    cin >> choice;
    if(choice == "Yes" || choice == "yes" || choice == "y") {
        cout << "##############################################################" << endl;
        cout << "PRINCE: " << endl;
        cout << "Greetings. Another seeker of royal favor, no doubt." << endl;
        cout << "##############################################################" << endl;
        int princeHP = 50;
        int emmaHP = 33;

        while (princeHP > 0 || emmaHP > 0) {
            vector<Dialogue::DialogueLine> options;
            options.push_back(Dialogue::getRandomCharacterLine());
            options.push_back(Dialogue::getRandomCharacterLine());

            int lineChoice;
            cout << endl;
            cout << "EMMA" << endl;
            cout << "1. " << options[0].line << " " << "("
                 << Entity::getTraitString(static_cast<Entity::TraitType>(options[0].trait)) << ")" << endl;
            cout << "2. " << options[1].line << " " << "("
                 << Entity::getTraitString(static_cast<Entity::TraitType>(options[1].trait)) << ")" << endl;
            cout << "Choose one response:  1 or 2" << endl;
            cin >> lineChoice;


            //wybrana opcja 1
            if (lineChoice == 1) {
                int damageEmma;
                int damagePrince;
                int princeDiceRoll = rand() % 3 + 1;
                int diceRoll = rand() % 3 + 1;

                damageEmma = emma.traits[options[0].trait] * diceRoll;
                damagePrince = prince.traits[options[0].trait] * princeDiceRoll;

                if (damageEmma < damagePrince) {
                    emmaHP = emmaHP - damagePrince;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "The prince isn't amazed by your "
                         << Entity::getTraitString(static_cast<Entity::TraitType>(options[0].trait)) << endl;
                    cout << endl;
                    cout << "Emma's HP: " << emmaHP << endl;
                    cout << "Prince's HP: " << princeHP << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                } else {
                    princeHP = princeHP - damageEmma;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "Good job! You're really good at talking." << endl;
                    cout << endl;
                    cout << "Emma's HP: " << emmaHP << endl;
                    cout << "Prince's HP: " << princeHP << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                }


                if (emmaHP <= 0) {
                    emma._chances = 0;
                    break;
                }

                if (princeHP <= 0) {
                    prince.isWonOver = true;
                    emma._chances = 0;
                    break;
                }

            } else if (lineChoice == 2) {
                int damageEmma;
                int damagePrince;
                int princeDiceRoll = rand() % 3 + 1;
                int diceRoll = rand() % 3 + 1;

                damageEmma = emma.traits[options[1].trait] * diceRoll;
                damagePrince = prince.traits[options[1].trait] * princeDiceRoll;

                //jesli obrażenia, które zada gracz są mniejsze niż admirera
                if (damageEmma < damagePrince) {
                    emmaHP = emmaHP - damagePrince;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "The prince isn't amazed by your "
                         << Entity::getTraitString(static_cast<Entity::TraitType>(options[1].trait)) << endl;
                    cout << endl;
                    cout << "Emma's HP: " << emmaHP << endl;
                    cout << "Prince's HP: " << princeHP << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                } else {
                    princeHP = princeHP - damageEmma;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << "Good job! You're really good at talking." << endl;
                    cout << endl;
                    cout << "Emma's HP: " << emmaHP << endl;
                    cout << "Prince's HP: " << princeHP << endl;
                    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                }
                if (emmaHP <= 0) {
                    emma._chances = 0;
                    break;
                }

                if (princeHP <= 0) {
                    prince.isWonOver = true;
                    emma._chances = 0;
                    break;
                }

            } else {
                cout << "It's not an option!" << endl;
            }
            cout << endl;
            cout << "PRINCE:" << endl;
            cout << Dialogue::getRandomNegativeAdmirerResponse() << endl;
        }
    }

}