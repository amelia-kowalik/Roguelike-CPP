#include "BattleSystem.h"
#include <iostream>
#include <cstdlib>
using namespace std;

void BattleSystem::seduction(Character &emma, Enemy admirer) {
    cout << "Would you like to seduct this gentleman" << endl;
    cout << "Yes or No?" << endl;
    string choice;
    cin >> choice;
    cout << endl;


    if (choice == "Yes") {
        cout << "ADMIRER" << endl;
        cout << Dialogue::getRandomStartingAdmirerDialogue(admirer.weakness) << endl;
        int admirerHP = 111;
        int emmaHP = 111;

        while (admirerHP > 0 || emmaHP > 0) {
            vector<Dialogue::DialogueLine> options;
            options.push_back(Dialogue::getRandomCharacterLine());
            options.push_back(Dialogue::getRandomCharacterLine());

            int lineChoice;
            cout << endl;
            cout << "EMMA" << endl;
            cout << "1. " << options[0].line << " " << "(" << options[0].trait << ")" << endl;
            cout << "2. " << options[1].line << " " << "(" << options[1].trait << ")" << endl;
            cout << "Choose one response:  1 or 2" << endl;
            cin >> lineChoice;


            //wybrana opcja 1
            if (lineChoice == 1) {
                int damageEmma = 0;
                int damageAdmirer = 0;
                int admirerDiceRoll = rand() % 3 + 1;
                int diceRoll = rand() % 3 + 1;

                //jesli gracz wybrał dialog zgodny ze słabością admirera
                if (options[0].trait == admirer.weakness) {
                    damageEmma = (emma.Trait[options[0].trait] + 3) * diceRoll; //+punkty z przedmiotów
                    damageAdmirer = admirer.weakness * admirerDiceRoll;

                    //jesli obrażenia, które zada gracz są mniejsze niż admirera
                    if (damageEmma < damageAdmirer) {
                        emmaHP = emmaHP - damageEmma;
                        cout << "Oh no! This gentleman's " << options[0].trait << "powers are stronger than yours!" << endl;
                        cout << "Emma's HP: " << emmaHP << endl;
                        cout << "Admirer's HP: " << admirerHP << endl;
                    } else {
                        admirerHP = admirerHP - damageEmma;
                        cout << "Bullseye! You really know how to talk to people!" << endl;
                        cout << "Emma's HP: " << emmaHP << endl;
                        cout << "Admirer's HP: " << admirerHP << endl;
                    }

                    //jesli gracz wybrał dialog NIEZGODNY ze słabością
                } else {
                    damageEmma = emma.Trait[options[0].trait] * diceRoll;
                    damageAdmirer = admirer.Trait[options[0].trait] * admirerDiceRoll;

                    if (damageEmma < damageAdmirer) {
                        emmaHP = emmaHP - damageEmma;
                        cout << "Oh no! This gentleman's " << options[0].trait << " powers are stronger than yours!" << endl;
                        cout << "Emma's HP: " << emmaHP << endl;
                        cout << "Admirer's HP: " << admirerHP << endl;
                    } else {
                        admirerHP = admirerHP - damageEmma;
                        cout << "Good job! You're really good at talking." << endl;
                        cout << "Emma's HP: " << emmaHP << endl;
                        cout << "Admirer's HP: " << admirerHP << endl;
                    }
                }

            } else if (lineChoice == 2) {
                int damageEmma = 0;
                int damageAdmirer = 0;
                int admirerDiceRoll = rand() % 3 + 1;
                int diceRoll = rand() % 3 + 1;

                //jesli gracz wybrał dialog zgodny ze słabością admirera
                if (options[0].trait == admirer.weakness) {
                    damageEmma = (emma.Trait[options[1].trait] + 3) * diceRoll; //+punkty z przedmiotów
                    damageAdmirer = admirer.weakness * admirerDiceRoll;

                    //jesli obrażenia, które zada gracz są mniejsze niż admirera
                    if (damageEmma < damageAdmirer) {
                        emmaHP = emmaHP - damageEmma;
                    } else {
                        admirerHP = admirerHP - damageEmma;
                    }

                    //jesli gracz wybrał dialog NIEZGODNY ze słabością
                } else {
                    damageEmma = emma.Trait[options[1].trait] * diceRoll;
                    damageAdmirer = admirer.Trait[options[1].trait] * admirerDiceRoll;

                    if (damageEmma < damageAdmirer) {
                        emmaHP = emmaHP - damageEmma;
                        cout << "Oh no! This gentleman's " << options[1].trait << " powers are stronger than yours!" << endl;
                        cout << "Emma's HP: " << emmaHP << endl;
                        cout << "Admirer's HP: " << admirerHP << endl;
                    } else {
                        admirerHP = admirerHP - damageEmma;
                        cout << "Good job! You're really good at talking." << endl;
                        cout << "Emma's HP: " << emmaHP << endl;
                        cout << "Admirer's HP: " << admirerHP << endl;
                    }
                }

            } else {
                cout << "It's not an option!" << endl;
            }

            if(emmaHP < 0){
                cout << Dialogue::getRandomNegativeAdmirerResponse() << endl;
                emma.lostBattle();
                break;
            }

            if(admirerHP < 0){
                admirer.isFree = false;
                cout << "ADMIRER:" << Dialogue::getRandomPositiveAdmirerResponse() << endl;
                emma.wonBattle();
                break;
            }
        }



        /*int weaknessWybranyUzytkownika_index = rand() % (sizeof(emma.Trait) / sizeof(emma.Trait[0]));
        int weaknessWylosowanyEnemy_index = rand() % (sizeof(admirer.Trait) / sizeof(admirer.Trait[0]));

        if (weaknessWybranyUzytkownika_index == weaknessWylosowanyEnemy_index) {
            return true;
        } else {
            if (emma.Trait[weaknessWybranyUzytkownika_index] >= admirer.Trait[weaknessWylosowanyEnemy_index]) {
                return true;
            } else
                return false;
        }
*/
    }
}
