#ifndef LOTR_DIALOGUE_H
#define LOTR_DIALOGUE_H
#include <iostream>
#include <vector>
#include "Entity.h"
using namespace std;

class Dialogue {

public:
    struct DialogueLine{
        string line;
        int trait;
        DialogueLine(string line, int trait) : line(line), trait(trait) {}
    };
        static vector<DialogueLine> startingAdmirerLine;
        static vector<DialogueLine> characterLine;
        static vector<DialogueLine> negativeAdmirerResponse;
        static vector<DialogueLine> positiveAdmirerResponse;

        Dialogue();
        static void addStartingAdmirerLine(string line,int trait);
        static void addCharacterLine(string line,int trait);
        static void addNegativeAdmirerResponse(string line,int trait);
        static void addPositiveAdmirerResponse(string line,int trait);

        static string getRandomStartingAdmirerDialogue(int desiredTrait);
        static DialogueLine getRandomCharacterLine();


};


#endif
