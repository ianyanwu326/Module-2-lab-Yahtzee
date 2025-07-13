#include "ConsoleUI.h"
#include <iostream>
#include <limits>

void ConsoleUI::displayWelcome() const {
  std::cout << "Welcome to Yahtzee!\n";
  std::cout << "===================\n\n";
}

void ConsoleUI::displayDice(const std::vector<int>& dice, const std::vector<bool>& heldStatus) const {
  std::cout << "Current Dice:\n";
  for (size_t i = 0; i < dice.size(); ++i) {
    std::cout << "Die " << (i + 1) << ": [" << dice[i] << "]";
    if (heldStatus[i]) {
      std::cout << " (Held)";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

void ConsoleUI::displayScoreOptions(const std::vector<std::string>& options, const std::vector<int>& scores) const {
  std::cout << "Available Scoring Options:\n";
  for (size_t i = 0; i < options.size(); ++i) {
    std::cout << (i + 1) << ". " << options[i];
    if (scores[i] != -1) {
      std::cout << " (Already scored: " << scores[i] << ")";
    }
    else {
      std::cout << " (Potential score: " << scores[i] << ")";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}

