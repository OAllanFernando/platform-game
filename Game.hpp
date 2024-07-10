#pragma once
#include <Box2D/Box2D.h>
#include "Chao.hpp"
#include "Jogador.hpp"
#include "Interface.hpp"  // Alteração: usar a interface gráfica genérica
#include "Teclas.hpp"

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
    Interface* interfaceGrafica;  // Alteração: usar a interface gráfica genérica
    b2World* world;

    Chao* chao;
    Jogador* jogador;
};
