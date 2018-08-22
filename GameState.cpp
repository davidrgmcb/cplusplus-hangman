#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
//#include "playerState.h" may need this may not
#include "GameState.h"
#include "PlayerState.h"
/* wordList class no longer necessary its job is taken up by a vector. Not really sure what class this lives in now? I guess probably gameState? Gotta go in something for proper OO dev.*/

GameState::GameState() {
    isEnd = false;
    std::string answer("Generic");
}
      
      void GameState::setAnswer() {
          srand(time(NULL));
          std::string word;
          std::vector<std::string> wordList;
          std::ifstream dictionary("/usr/share/dict/words");
          while(std::getline(dictionary, word)) {
              wordList.push_back(word);
          }
          //std::cout << "Vector size: " << wordList.size() << '\n';
          int element = rand() % wordList.size();
          this->answer = wordList[element];
          //std::cout << "Random word: " << wordList[element] << '\n';
          //std::cout << "String Length = " << wordList[element].length() << '\n';
          for(int ii = 0; ii < answer.length(); ii++) {
              this->answer[ii] = tolower(this->answer[ii]);
          }
          //std::cout << "Random word: " << answer << '\n';
          }
      
      void GameState::fillCorrectlyGuessed(PlayerState player) {
          player.correctlyGuessed.assign(this->answer.length(), '_'); //Encapsulate this
          return;
      }
    
      void GameState::testGuess(PlayerState player) {
          for (int ii = 0; ii < answer.length(); ii++) {
            if (player.currentGuess[0] == this->answer[ii]) {
                //player.correctlyGuessed[ii] = player.currentGuess[0];
                player.updateCorrectlyGuessed(ii);
                if (ii == this->answer.length()) {
                    return;
                }
            }
          else { //This construction won't work, need to rethink it.
                player.isStrike();
          }
          }
      }
      
      void GameState::isGameOver(PlayerState player) {
          if (player.strikes >= 7) {
              this->isEnd = true;
              return;
          }
          else {
              return;
          }
      }
      
      void GameState::addApostrophes(PlayerState player) {
          for (int ii = 0; ii < answer.length(); ii++) {
              if (this->answer[ii] == '\'') {
                  player.correctlyGuessedApostrophes(ii);
                  return;
              }
          }
      }
