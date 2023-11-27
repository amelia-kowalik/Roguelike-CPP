#ifndef LOTR_ENTITY_H
#define LOTR_ENTITY_H
#include <string>
using namespace std;

class Entity {
public:
    string _name;
    int _row, _column;

    enum TraitType{
        MANIPULATION = 0,
        CHARM = 1,
        INTELLIGENCE = 2,
        CHARISMA = 3
    };

    int Traits[4];

    Entity();
    Entity(int manipulation, int charisma, int intelligence, int charm);
    void setPos(int row, int column);
    void getPos(int &row, int &column);

};


#endif