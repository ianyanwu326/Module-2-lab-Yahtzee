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

std::vector<bool> ConsoleUI::getDiceToHold(int diceCount) const {
  std::vector<bool> holds(diceCount, false);
  std::string input;

  std::cout << "Enter which dice to hold (1-5), separated by spaces (e.g., 1 3 5): ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::getline(std::cin, input);

  size_t pos = 0;
  while (pos < input.length()) {
    if (isdigit(input[pos])) {
      int dieNum = input[pos] - '0';
      if (dieNum >= 1 && dieNum <= diceCount) {
        holds[dieNum - 1] = true;
      }
    }
    pos++;
  }

  return holds;
}

int ConsoleUI::getScoreChoice(const std::vector<std::string>& options) const {
  int choice;
  while (true) {
    std::cout << "Select a category to score (1-" << options.size() << "): ";
    std::cin >> choice;

    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Invalid input. Please enter a number.\n";
    }
    else if (choice < 1 || choice > static_cast<int>(options.size())) {
      std::cout << "Invalid choice. Please select a number between 1 and " << options.size() << ".\n";
    }
    else {
      break;
    }
  }
  return choice - 1; // Convert to 0-based index
}

bool ConsoleUI::promptPlayAgain() const {
  char response;
  std::cout << "Would you like to play again? (y/n): ";
  std::cin >> response;
  return (response == 'y' || response == 'Y');
}

void ConsoleUI::displayMessage(const std::string& message) const {
  std::cout << message << "\n";
}

void ConsoleUI::displayFinalScore(int score) const {
  std::cout << "\nGame Over!\n";
  std::cout << "Your final score: " << score << "\n\n";
}