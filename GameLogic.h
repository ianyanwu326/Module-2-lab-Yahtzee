#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H
#include "Die.h"
#include <vector>
#include <string>

class GameLogic {
private:
  std::vector <Die> dice;
  int rollsRemaining;
  std::vector<int> scores;
  std::vector<bool> categoriesUsed;

  void rollAllUnheldDice();
  
  

public:
  GameLogic();

  void startNewRound();
  void rollDice(const std::vector<bool>& diceToHold);
  bool canRollAgain() const;
  bool isRoundOver() const;

  std::vector<int> getCurrentDiceValues() const;
  std::vector<bool> getCurrentDiceHoldStatus() const;

  std::vector<std::string> getAvailableCategories() const;
  bool recordScoreForCategory(int category);

  int getTotalScore() const;
  bool isGameOver() const;

  bool isCategoryUsed(int category) const; 

  int calculateScoreForCategory(int category) const;

};

#endif