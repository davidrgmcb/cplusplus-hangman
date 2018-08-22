#include "GameState.h"
#include "PlayerState.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    PlayerState player = new PlayerState::PlayerState;
    GameState game = new GameState::GameState;
    game.setAnswer();
    game.fillCorrectlyGuessed(player);
    game.addApostrophes(player);
    while(!game.isEnd) {
        std::cout << "" << player.correctlyGuessed << "\n";
        player.getGuess();
        game.testGuess(player); //Expect this to improperly increment strikes and possibly instantly end the game
        game.isEnd(player);
    }
    std::cout << "The answer was " << game.answer << "\n"; //Being as this is a private variable this may very well not work.
}