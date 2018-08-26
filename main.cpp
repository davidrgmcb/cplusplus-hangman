#include "GameState.h"
#include "PlayerState.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    PlayerState player;
    //player = new PlayerState;
    GameState game;
    //game =new GameState;
    game.setAnswer();
    game.fillCorrectlyGuessed(player);
    game.addApostrophes(player);
    while(!game.isEnd) {
        std::cout << "" << player.correctlyGuessed << "\n" << player.strikes << "\n";
        player.getGuess();
        game.testGuess(player); //Expect this to improperly increment strikes and possibly instantly end the game
        game.isGameOver(player);
    }
    if (player.strikes < 7) {
        std::cout << "Good job! The answer was " << game.answer << "\n"; //Being as this is a private variable this may very well not work. Replace this with a geter I guess
    }
    else {
        std::cout << "Too Bad! The answer was " << game.answer << "\n"; //Being as this is a private variable this may very well not work. Replace this with a geter I guess
    }
}