#include "Game.hpp"
#include "SdlInterfaceImpl.hpp"
#include <iostream>

Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
    : isRunning(false), interfaceGrafica(new SdlInterfaceImpl()) {  // Alteração: inicializar com implementação SDL
    b2Vec2 gravity(0, 0.10);
    world = new b2World(gravity);

    int flags = 0;
    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    interfaceGrafica->criaJanela(title, xpos, ypos, width, height, flags);
    interfaceGrafica->criaRenderer(-1, 0);

    if (interfaceGrafica->janelaValida() && interfaceGrafica->rendererValido()) {
        interfaceGrafica->defineCor(10, 0, 0, 100);
        isRunning = true;
    }
    else {
        isRunning = false;
    }

    chao = new Chao(world, interfaceGrafica, 0.0f, 500.0f, width, 100.0f);
    jogador = new Jogador(world, interfaceGrafica, 100.0f, 440.0f);  // Alteração: passar interface gráfica para jogador
    
    //jogador->setPontos(10);
    //print de teste
    std::cout << "Game::Game() - Game criado " << jogador->getPontos() << std::endl;
}

Game::~Game() {
    delete jogador;
    delete chao;
    delete world;

    interfaceGrafica->destroiRenderer();
    interfaceGrafica->destroiJanela();

    SDL_Quit();

    delete interfaceGrafica;  // Alteração: liberar memória da interface gráfica
}

void Game::handleEvents() {
    // vamos validar quando receber um evento para up para só pular se relar no chao
    

    Key key = Key::NONE;
    while (interfaceGrafica->pollEvent(key)) {
        switch (key) {
        case Key::QUIT:
            isRunning = false;
            break;
        case Key::UP :
        case Key::DOWN:
        case Key::LEFT:
        case Key::RIGHT:
            jogador->tecla(key);
            break;
        default:
            break;
        }
    }
}

void Game::update() {
    world->Step(1.0f / 60.0f, 6, 3);
}

void Game::render() {
    interfaceGrafica->defineCor(0, 0, 100, 255);
    interfaceGrafica->limpaRenderer();

    interfaceGrafica->defineCor(10, 100, 50, 255);
    chao->render();

    jogador->render();

    interfaceGrafica->renderPresent();
}


static bool tocaChao(b2Body* jogadorCorpo, b2Body* chaoCorpo) {
	b2AABB aabbJogador = jogadorCorpo->GetFixtureList()->GetAABB(0);
	b2AABB aabbChao = chaoCorpo->GetFixtureList()->GetAABB(0);

	return aabbJogador.lowerBound.y <= aabbChao.upperBound.y;
}
