#include "Enemy.h"

Enemy::Enemy() {}


void Enemy::setWeakness() {
    weakness = rand() % sizeof(Trait);

}