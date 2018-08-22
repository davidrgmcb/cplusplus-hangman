#include <iostream>
#include <vector>

#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

class PlayerState {
    public:
      int strikes;
      std::string currentGuess;
      std::vector<char> alreadyGuessed;
      std::string correctlyGuessed;
      
      void getGuess(std::string currentGuess);
      
      void isStrike();
      
      void updateCorrectlyGuessed(int ii);
      
      void correctlyGuessedApostrophes(int ii);
      
      PlayerState();
};

#endif