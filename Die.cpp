#include "Die.h"
#include <cstdlib>
#include <ctime>

Die::Die(int numSides) : sides(numSides), faceValue(1), isHeld(false) {
  std::srand(std::time(0)); // Seed random number generator
}

void Die::roll() {
  if (!isHeld) {
    faceValue = (std::rand() % sides) + 1;
  }
}

int Die::getFaceValue() const {
  return faceValue;
}

bool Die::getIsHeld() const {
  return isHeld;
}

void Die::toggleHold() {
  isHeld = !isHeld;
}

void Die::resetHold() {
  isHeld = false;
}
