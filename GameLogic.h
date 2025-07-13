#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <vector>
#include <string>

class GameLogic {
private:
  std::vector<Die> dice;
  int rollsRemaining;
  std::vector<int> scores;
  std::vector<bool> categoriesUsed;

  void rollAllUnheldDice();
  int calculateScoreForCategory(int category) const;
  bool isCategoryUsed(int category) const;

