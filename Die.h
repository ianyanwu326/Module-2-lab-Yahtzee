// Die.h
#ifndef DIE_H
#define DIE_H

class Die {
private:
  int faceValue;
  int sides;
  bool isHeld;

public:
  Die(int numSides = 6);
  void roll();
  int getFaceValue() const;
  bool getIsHeld() const;
  void toggleHold();
  void resetHold();
};

#endif


