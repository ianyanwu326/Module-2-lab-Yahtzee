#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include <vector>
#include <string>

class ConsoleUI {
public:
  void displayWelcome() const;
  void displayDice(const std::vector<int>& dice, const std::vector<bool>& heldStatus) const;
  void displayScoreOptions(const std::vector<std::string>& options, const std::vector<int>& scores) const;

  
