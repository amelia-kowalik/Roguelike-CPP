#ifndef LOTR_ENEMY_H
#define LOTR_ENEMY_H
#include "Character.h"

class Enemy : public Entity {
public:
    Enemy();

    Enemy(int manipulation, int charisma, int intelligence, int charm);

    bool isFree = true;
    int weakness;
    void setWeakness();


};
#endif
