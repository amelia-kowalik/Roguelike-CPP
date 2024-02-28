#include "Boss.h"

Boss::Boss() {}

Boss::Boss(int manipulation, int charisma, int intelligence, int charm, bool isWonOver) : Entity(manipulation, charisma,
                                                                                                 intelligence, charm),
                                                                                          isWonOver(isWonOver) {}


