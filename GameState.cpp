#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "GameState.h"
#include "PlayerState.h"
/* wordList class no longer necessary its job is taken up by a vector. Not really sure what class this lives in now? I guess probably GameState? Gotta go in something for proper OO dev.*/

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
      
      void GameState::fillCorrectlyGuessed(PlayerState &player) {
          player.correctlyGuessed.assign(this->answer.length(), '_'); //Encapsulate this
          return;
      }
    
      void GameState::testGuess(PlayerState &player) {
          bool isStrike = true;
          for (int ii = 0; ii <= answer.length(); ii++) {
            if (player.currentGuess[0] == this->answer[ii]) {
                player.updateCorrectlyGuessed(ii);
                isStrike = false;
                if (ii >= this->answer.length() && isStrike == false) {
                    return;
                }
            }
            else if (ii >= this->answer.length() && isStrike == true) { //This construction won't work, need to rethink it.
                player.isStrike();
                return;
            }
          }
      }
      
      void GameState::isGameOver(PlayerState &player) {
          if (player.strikes >= 7 || this->answer.compare(player.correctlyGuessed) == 0) {
              this->isEnd = true;
              return;
          }
          else {
              return;
          }
      }
      
      void GameState::addApostrophes(PlayerState &player) {
          for (int ii = 0; ii < answer.length(); ii++) {
              if (this->answer[ii] == '\'') {
                  player.correctlyGuessedApostrophes(ii);
                  return;
              }
          }
      }
      
      bool GameState::revealEndStatus() {
          return isEnd;
      }
      
      std::string GameState::revealAnswer() {
          return answer;
      }
