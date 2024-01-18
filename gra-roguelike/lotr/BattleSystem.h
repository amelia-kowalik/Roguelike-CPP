#ifndef LOTR_BATTLESYSTEM_H
#define LOTR_BATTLESYSTEM_H
#include "Entity.h"
#include "Character.h"
#include "Enemy.h"
#include "Dialogue.h"


class BattleSystem {
public:
   static void seduction(Character &emma, Enemy &admirer);
};


#endif