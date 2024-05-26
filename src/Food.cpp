#include "Food.h"
#include "Constants.h"
#include <cstdlib>

Food::Food() {
    respawn();
}

void Food::respawn() {
    x = (std::rand() % (800 / Constants::SIZE)) * Constants::SIZE;
    y = (std::rand() % (600 / Constants::SIZE)) * Constants::SIZE;
}

int Food::getX() const { return x; }
int Food::getY() const { return y; }