#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "classes.h"
/* wordList class no longer necessary its job is taken up by a vector. Not really sure what class this lives in now? I guess probably gameState? Gotta go in something for proper OO dev.*/

/*class gameState {
    private:*/
      classes::gameState isEnd = false;
      classes::gameState std::string answer("Generic")
      
      void classes::gameState setAnswer() {
          srand(time(NULL));
          std::string word;
          std::vector<std::string> wordList;
          std::ifstream dictionary("/usr/share/dict/words");
          while(std::getline(dictionary, word)) {
              wordList.push_back(word);
          }
          //std::cout << "Vector size: " << wordList.size() << '\n';
          int element = rand() % wordList.size();
          this.answer = wordList[element];
          //std::cout << "Random word: " << wordList[element] << '\n';
          //std::cout << "String Length = " << wordList[element].length() << '\n';
          for(int ii = 0; ii < answer.length(); ii++) {
              this.answer[ii] = tolower(this.answer[ii]);
          }
          //std::cout << "Random word: " << answer << '\n';
          }
      
      void classes::gameState fillCorrectlyGuessed(playerState player) {
          player.correctlyGuessed.assign(this.answer.length(), '_'); //Encapsulate this
          return;
      }
    
      void classes::gameState testGuess(playerState player) {
          for (int ii = 0; ii < answer.length(); ii++) {
            if (player.currentGuess[0] == this.answer[ii] {
                //player.correctlyGuessed[ii] = player.currentGuess[0];
                player.updateCorrectlyGuessed(ii);
                if (ii == this.answer.length()) {
                    return;
                }
            }
          else { //This construction won't work, need to rethink it.
                player.isStrike();
          }
          }
      }
      
      void classes::gameState isGameOver(playerState player) {
          if (player.strikes >= 7) {
              this.isEnd = true;
              return;
          }
          else {
              return;
          }
      }
      
      void classes::gameState addApostrophes(playerState player) {
          for (int ii = 0; ii < answer.length(); ii++) {
              if (this.answer[ii] == '\'') {
                  player.correctlyGuessedApostrophes(ii);
                  return;
              }
          }
      }
};

/*class playerState {
    public:*/
      classes::playerState strikes = 0;
      classes::playerState currentGuess('a');
      classes::playerState correctlyGuessed('_')
      
      void classes::playerState getGuess() {
          this.currentGuess = fgets(currentGuess, currentGuess.max_size, stdin);
          if (isalpha(currentGuess[0]) == 0) {
              std::cout << "Please type one letter, no numbers or symboles\n";
              getGuess(std::string currentGuess);
          }
          this.currentGuess.pop_back();
          for (int ii = 0; ii < alreadyGuessed.size(); ii++) {
              if (currentGuess[0] == alreadyGuessed[ii]) {
                  std::cout << "You already guessed that, please guess something different\n";
                  return;
              }
          }
          this.alreadyGuessed.push_back(currentGuess[0]);
      }
      
      void classes::playerState isStrike() {
          this.stirkes++;
      }
      
      void classes::playerState updateCorrectlyGuessed(int ii) {
          this.correctlyGuessed[ii] = this.currentGuess[0];
          return;
      }
      
      void classes::playerState correctlyGuessedApostrophes(int ii) {
          this.correctlyGuessed[ii] = '\'';
          return;
      }
};