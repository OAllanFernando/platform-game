#include "Game.hpp"
#include "interface.hpp"
#include <SDL.h>
#include <Box2D/Box2D.h>
#include "jogador.hpp"
#include "Chao.hpp"

int main(int argc, char* argv[]) {
    Game* game = new Game("Runaway", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);



    while (game->running()) {
        
        game->handleEvents();
        game->update();
        game->render();

    }

    delete game;

    return 0;
}