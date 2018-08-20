#include "classes.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    new classes::playerState player;
    new classes::gameState game;
    game.setAnswer();
    game.fillCorrectlyGuessed(player);
    game.addApostrophes(player);
    while(!game.isEnd) {
        cout << "" << player.correctlyGuessed;
        player.getGuess();
        game.testGuess(player); //Expect this to improperly increment strikes and possibly instantly end the game
        game.isEnd(player);
    }
    cout << "The answer was " << game.answer; //Being as this is a private variable this may very well not work.
}