#include "Dialogue.h"

Dialogue::Dialogue(){}

vector<Dialogue::DialogueLine> Dialogue::startingAdmirerLine;
vector<Dialogue::DialogueLine> Dialogue::characterLine;
vector<Dialogue::DialogueLine> Dialogue::negativeAdmirerResponse;
vector<Dialogue::DialogueLine> Dialogue::positiveAdmirerResponse;

void Dialogue::addStartingAdmirerLine(string line, int trait) {
    Dialogue::startingAdmirerLine.push_back(DialogueLine(line, trait));
}

void Dialogue::addCharacterLine(std::string line, int trait) {
    Dialogue::characterLine.push_back(DialogueLine(line, trait));
}

void Dialogue::addNegativeAdmirerResponse(string line, int trait) {
    Dialogue::negativeAdmirerResponse.push_back(DialogueLine(line, trait));
}

void Dialogue::addPositiveAdmirerResponse(string line, int trait){
    Dialogue::positiveAdmirerResponse.push_back(DialogueLine(line, trait));
}

string Dialogue::getRandomStartingAdmirerDialogue(int desiredTrait){
    vector<string> filteredDialogues;
    for (size_t i = 0; i < startingAdmirerLine.size(); ++i) {
        if (startingAdmirerLine[i].trait == desiredTrait) {
            filteredDialogues.push_back(startingAdmirerLine[i].line);
        }
    }
    int index = rand() % filteredDialogues.size();
    return filteredDialogues[index];
}

Dialogue::DialogueLine Dialogue::getRandomCharacterLine(){
    int index = rand() % characterLine.size();
    return characterLine[index];
}