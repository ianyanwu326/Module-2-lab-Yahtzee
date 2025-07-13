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

