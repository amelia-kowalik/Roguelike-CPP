#ifndef LOTR_ENTITY_H
#define LOTR_ENTITY_H
#include <string>
#include <array>
using namespace std;

class Entity {
public:
    int _row, _column;

    enum TraitType {
        MANIPULATION = 0,
        CHARM = 1,
        INTELLIGENCE = 2,
        CHARISMA = 3,
        NOTRAIT = 4
    };

    static const char* revTrait[4];
    array<int, 4> traits;
    static string getTraitString(TraitType trait);

    Entity();
    Entity(int manipulation, int charisma, int intelligence, int charm);
    void setPos(int row, int column);
    void getPos(int &row, int &column);

};


#endif