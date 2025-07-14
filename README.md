  Okay so in this read me i will talk about the purpose of my code, the structure and how it functions 
  This was for my Computer science 2 assignment project.
  The implementation is from a C++ version of the Yahtzee dice game. It uses classes to keep things organized. One player can roll dice, hold some between rolls, and score in different categories 

  My project has specific classes all playing key roles to enable the code to function accurately. 
  
  Die.h/Die.cpp - Manages individual dice behavior
GameLogic.h/GameLogic.cpp - Handles game rules and scoring
ConsoleUI.h/ConsoleUI.cpp - Manages all user interactions
Yahtzee.cpp - Contains the main game loop 

Then now looking at the key factor how to play it is simple it follows some couple steps like:--- firstly Roll dice automatic first roll secondly  Choose dice to hold between rolls Then after 3 rolls, pick scoring category
lastly the game ends when all categories are filled. 

Some highlights from the code are----- DICE(provides methods to roll and rest) 
class Die {
private:
  int faceValue;
  int sides;
  bool isHeld; 
public:
  Die(int numSides = 6);
  void roll();
  int getFaceValue() const;
  bool getIsHeld() const;
  void toggleHold();
  void resetHold();
};


GAME CLASS ---- Manage game state and rules 
class GameLogic {
private:
  std::vector<Die> dice;
  int rollsRemaining;
  std::vector<int> scores;
  std::vector<bool> categoriesUsed;
  // ... methods ...
};

ConsoleUI provides clear feeedback to players
class ConsoleUI {
public:
  void displayWelcome() const;
  void displayDice(const std::vector<int>& dice, const std::vector<bool>& heldStatus) const;
  void displayScoreOptions(const std::vector<std::string>& options, const std::vector<int>& scores) const;
  // ... more methods ...
};

