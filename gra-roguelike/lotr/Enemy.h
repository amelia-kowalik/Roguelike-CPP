#ifndef LOTR_ENEMY_H
#define LOTR_ENEMY_H
#include "Character.h"

class Enemy : public Entity {
public:
    Enemy();
    bool isFree;
    int weakness;
    void setWeakness();


};
#endif