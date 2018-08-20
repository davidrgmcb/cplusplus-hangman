#include <iostream>
/*#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>*/



class gameState {
    private:
      bool isEnd;
      std::string answer;
      
      void setAnswer();
      
      void fillCorrectlyGuessed(playerState player);
    
      void testGuess(playerState player);
      
      void isGameOver(playerState player);
      
      void addApostrophes(playerState player);

class playerState {
    public:
      int strikes;
      std::string currentGuess;
      std::vector<char> alreadyGuessed;
      std::string correctlyGuessed;
      
      void getGuess(std::string currentGuess);
      
      void isStrike();
      
      void updateCorrectlyGuessed(int ii);
      
      void correctlyGuessedApostrophes(int ii);