#include <iostream>
#include "GameController.h"

int main() {
    GameController game(5,7);

    while (!game.gameOver()) {
        game.printMap();
        game.takeTurn();

    }
        return 0;
}