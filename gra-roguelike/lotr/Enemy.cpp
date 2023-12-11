#include "Enemy.h"

Enemy::Enemy() {
    setWeakness();
    isFree = true;
}

void Enemy::setWeakness() {
    srand(time(NULL));
//    weakness = rand() % (sizeof(Trait)/sizeof(Trait[0]));
    weakness = rand() % Trait.size();
}

Enemy::Enemy(int manipulation, int charisma, int intelligence, int charm) : Entity(
        manipulation, charisma, intelligence, charm) {
    setWeakness();
}
