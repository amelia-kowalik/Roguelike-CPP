#ifndef LOTR_BOSS_H
#define LOTR_BOSS_H
#include "Enemy.h"


class Boss : public Entity{
public:
    Boss();
    Boss(int manipulation, int charisma, int intelligence, int charm, bool isWonOver);
    bool isWonOver = false;

};


#endif
