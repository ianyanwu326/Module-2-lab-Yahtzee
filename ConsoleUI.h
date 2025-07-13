#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include <vector>
#include <string>

class ConsoleUI {
public:
  void displayWelcome() const;
  void displayDice(const std::vector<int>& dice, const std::vector<bool>& heldStatus) const;
  void displayScoreOptions(const std::vector<std::string>& options, const std::vector<int>& scores) const;

  std::vector<bool> getDiceToHold(int diceCount) const;
  int getScoreChoice(const std::vector<std::string>& options) const;
  bool promptPlayAgain() const;
  void displayMessage(const std::string& message) const;
  void displayFinalScore(int score) const;
};

#endif
