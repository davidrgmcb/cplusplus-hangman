#include <iostream>
#include <vector>
#include "PlayerState.h"

PlayerState::PlayerState() {
    strikes = 0;
    std::string currentGuess("a");
    std::string correctlyGuessed("_");
}
      
      void PlayerState::getGuess() {
          this->currentGuess = fgets(currentGuess, currentGuess.max_size, stdin); //This is producing headaches, just try cin
          if (isalpha(currentGuess[0]) == 0) {
              std::cout << "Please type one letter, no numbers or symboles\n";
              getGuess(std::string currentGuess);
          }
          this->currentGuess.pop_back();
          for (int ii = 0; ii < alreadyGuessed.size(); ii++) {
              if (currentGuess[0] == alreadyGuessed[ii]) {
                  std::cout << "You already guessed that, please guess something different\n";
                  return;
              }
          }
          this->alreadyGuessed.push_back(currentGuess[0]);
      }
      
      void PlayerState::isStrike() {
          this->strikes++;
      }
      
      void PlayerState::updateCorrectlyGuessed(int ii) {
          this->correctlyGuessed[ii] = this->currentGuess[0];
          return;
      }
      
      void PlayerState::correctlyGuessedApostrophes(int ii) {
          this->correctlyGuessed[ii] = '\'';
          return;
      }
