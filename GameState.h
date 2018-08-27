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
      
  public:
      GameState();
      
      void setAnswer();
      
      void fillCorrectlyGuessed(PlayerState &player);
    
      void testGuess(PlayerState &player);
      
      void isGameOver(PlayerState &player);
      
      void addApostrophes(PlayerState &player);
      
      bool revealEndStatus();
      
      std::string revealAnswer(); //Honestly this isn't even any better but I'd need to understand encapsulation better to have a better solution than just a getter.
      
};

#endif