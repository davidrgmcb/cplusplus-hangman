#include "GameState.h"
#include "PlayerState.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    PlayerState player;
    GameState game;
    game.setAnswer();
    game.fillCorrectlyGuessed(player);
    game.addApostrophes(player);
    while(!game.revealEndStatus()) {
        std::cout << "" << player.correctlyGuessed << "\n" << player.strikes << "\n";
        player.getGuess();
        game.testGuess(player);
        game.isGameOver(player);
    }
    if (player.strikes < 7) {
        std::cout << "Good job! The answer was " << game.revealAnswer() << "\n"; 
    }
    else {
        std::cout << "Too Bad! The answer was " << game.revealAnswer() << "\n"; 
    }
}