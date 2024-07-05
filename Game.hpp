// Game.hpp
#pragma once
#include <SDL.h>
#include <Box2D/Box2D.h>
#include "Chao.hpp"
#include "Jogador.hpp"
#include "SdlInterfaceImpl.hpp" // Inclua a implementação do SDL usando a interface

class Game {
public:
    Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    ~Game();

    void handleEvents();
    void update();
    void render();
    bool running() { return isRunning; }

private:
    bool isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
    b2World* world;
    Chao* chao;
    Jogador* jogador;
    SdlInterfaceImpl interfaceGrafica;
};
