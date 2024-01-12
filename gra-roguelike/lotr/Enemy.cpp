#include "Enemy.h"

Enemy::Enemy() {
    setWeakness();
    isFree = true;
}

void Enemy::setWeakness() {
    weakness = rand() % Trait.size();
}

Enemy::Enemy(int manipulation, int charisma, int intelligence, int charm) : Entity(
        manipulation, charisma, intelligence, charm) {
    setWeakness();
}
