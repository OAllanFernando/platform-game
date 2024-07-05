// Game.cpp
#include "Game.hpp"
#include "SdlInterfaceImpl.hpp"

Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
    : isRunning(false), window(nullptr), renderer(nullptr) {
    b2Vec2 gravity(0, 0.10);
    world = new b2World(gravity);

    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    window = interfaceGrafica.criaJanela(title, xpos, ypos, width, height, flags);
    renderer = interfaceGrafica.criaRenderer(window, -1, 0);

    if (window && renderer) {
        interfaceGrafica.defineCor(renderer, 10, 0, 0, 100);
        isRunning = true;
    }
    else {
        isRunning = false;
    }

    chao = new Chao(world, renderer, 400.0f, 500.0f, 400.0f, 100.0f);
    jogador = new Jogador(world, &interfaceGrafica, 200.0f, 300.0f);
}

Game::~Game() {
    delete jogador;
    delete chao;
    delete world;

    interfaceGrafica.destroiRenderer(renderer);
    interfaceGrafica.destroiJanela(window);
    SDL_Quit();
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_KEYDOWN:
        jogador->tecla(event);
        break;
    default:
        break;
    }
}

void Game::update() {
    world->Step(1.0f / 60.0f, 6, 3);
}

void Game::render() {
    interfaceGrafica.defineCor(renderer, 0, 0, 100, 255);
    interfaceGrafica.limpaRenderer(renderer);

    interfaceGrafica.defineCor(renderer, 10, 100, 50, 255);
    chao->render();

    jogador->render();

    interfaceGrafica.renderPresent(renderer);
}
