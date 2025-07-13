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
      