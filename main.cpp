#include <iostream>

#include "game.h"

int main() {

    //Random init
    srand(static_cast<unsigned>(time(NULL)));

    //Create game engine
    Game game;

    //Game loop
    while (game.getWindowIsOpen()) {

        //Update
        game.update();

        //Render
        game.render();

    }

    return 0;
}