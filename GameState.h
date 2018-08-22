#include <iostream>
#include <vector>
/*#include <fstream>
#include <string>

#include <cstdlib>
#include <ctime>*/

#ifndef GAMESTATE_H
#define GAMESTATE_H

class PlayerState;

class GameState {
    private:
      bool isEnd;
      std::string answer;
      
      void setAnswer();
      
      void fillCorrectlyGuessed(PlayerState player);
    
      void testGuess(PlayerState player);
      
      void isGameOver(PlayerState player);
      
      void addApostrophes(PlayerState player);
      
      GameState();
      
      ~GameState();
};

#endif