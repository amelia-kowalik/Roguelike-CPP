#include "Enemy.h"

Enemy::Enemy() {
    setWeakness();
}

void Enemy::setWeakness() {
//    weakness = rand() % (sizeof(Trait)/sizeof(Trait[0]));
    weakness = rand() % Trait.size();
}