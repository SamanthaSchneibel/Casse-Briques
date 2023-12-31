#include "game.hpp"

int main(int argc, char** argv) {

    Game game;

    while (game.isRunning())
    {
        game.event();
        game.update();
        game.draw();
    }

    return 0;
}