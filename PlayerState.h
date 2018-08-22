#include <iostream>
#include <vector>
#include <cstdio>

#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

class PlayerState {
    public:
      int strikes;
      std::string currentGuess;
      std::vector<char> alreadyGuessed;
      std::string correctlyGuessed;
      
      void getGuess();
      
      void isStrike();
      
      void updateCorrectlyGuessed(int ii);
      
      void correctlyGuessedApostrophes(int ii);
      
      PlayerState();
};

#endif