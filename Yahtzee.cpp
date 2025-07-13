#include "GameLogic.h"
#include "ConsoleUI.h"
#include <iostream>

int main() {
  ConsoleUI ui;
  GameLogic game;

  ui.displayWelcome();

  do {
    game.startNewRound();

    while (!game.isRoundOver()) {
      ui.displayDice(game.getCurrentDiceValues(), game.getCurrentDiceHoldStatus());

      if (game.canRollAgain()) {
        std::vector<bool> diceToHold = ui.getDiceToHold(5);
        game.rollDice(diceToHold);
      }
      else {
        std::vector<std::string> categories = game.getAvailableCategories();
        std::vector<int> potentialScores;
        for (size_t i = 0; i < categories.size(); ++i) {
          potentialScores.push_back(game.isCategoryUsed(i) ? -1 : game.calculateScoreForCategory(i));
        }

        ui.displayScoreOptions(categories, potentialScores);
        int choice = ui.getScoreChoice(categories);
        game.recordScoreForCategory(choice);

        if (!game.isGameOver()) {
          game.startNewRound();
        }
      }
    }

    ui.displayFinalScore(game.getTotalScore());
  } while (ui.promptPlayAgain());

  return 0;
}