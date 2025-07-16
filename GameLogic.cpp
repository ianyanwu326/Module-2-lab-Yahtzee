 #include "GameLogic.h"
#include "Die.h"
#include <algorithm>

GameLogic::GameLogic() : dice(5), rollsRemaining(0) {
  // Initialize categories (aces through sixes)
  categoriesUsed = std::vector<bool>(6, false);
  scores = std::vector<int>(6, -1); // -1 means not scored yet
}

void GameLogic::startNewRound() {
  rollsRemaining = 3;
  for (auto& die : dice) {
    die.resetHold();
    die.roll();
  }
}

void GameLogic::rollAllUnheldDice() {
  for (auto& die : dice) {
    die.roll();
  }
}

void GameLogic::rollDice(const std::vector<bool>& diceToHold) {
  if (rollsRemaining <= 0) return;

  // Set hold status based on user input
  for (size_t i = 0; i < dice.size(); ++i) {
    if (diceToHold[i]) {
      dice[i].toggleHold();
    }
  }

  rollAllUnheldDice();
  rollsRemaining--;

  // Reset hold status for next roll
  for (auto& die : dice) {
    die.resetHold();
  }
}

bool GameLogic::canRollAgain() const {
  return rollsRemaining > 0 && !isGameOver();
}

bool GameLogic::isRoundOver() const {
  return rollsRemaining == 0 || isGameOver();
}

std::vector<int> GameLogic::getCurrentDiceValues() const {
  std::vector<int> values;
  for (const auto& die : dice) {
    values.push_back(die.getFaceValue());
  }
  return values;
}

std::vector<bool> GameLogic::getCurrentDiceHoldStatus() const {
  std::vector<bool> status;
  for (const auto& die : dice) {
    status.push_back(die.getIsHeld());
  }
  return status;
}

std::vector<std::string> GameLogic::getAvailableCategories() const {
  std::vector<std::string> categories = {
      "Aces (Sum of 1s)",
      "Twos (Sum of 2s)",
      "Threes (Sum of 3s)",
      "Fours (Sum of 4s)",
      "Fives (Sum of 5s)",
      "Sixes (Sum of 6s)"
  };

  return categories;
}

int GameLogic::calculateScoreForCategory(int category) const {
  if (category < 0 || category >= 6) return 0;

  int target = category + 1; // categories are 0-5 for 1-6
  int sum = 0;

  for (const auto& die : dice) {
    if (die.getFaceValue() == target) {
      sum += target;
    }
  }

  return sum;
}

bool GameLogic::recordScoreForCategory(int category) {
  if (category < 0 || category >= 6 || isCategoryUsed(category)) {
    return false;
  }

  scores[category] = calculateScoreForCategory(category);
  categoriesUsed[category] = true;
  return true;
}

bool GameLogic::isCategoryUsed(int category) const {
  return categoriesUsed[category];
}

int GameLogic::getTotalScore() const {
  int total = 0;
  for (int score : scores) {
    if (score != -1) {
      total += score;
    }
  }
  return total;
}

bool GameLogic::isGameOver() const {
  for (bool used : categoriesUsed) {
    if (!used) return false;
  }
  return true;
}