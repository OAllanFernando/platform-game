// SdlInterfaceImpl.hpp
#pragma once
#include "Interface.hpp"
#include <Box2D/Box2D.h>

class SdlInterfaceImpl : public Interface {
public:
    SdlInterfaceImpl();
    SDL_Window* criaJanela(const char* title, int x, int y, int w, int h, Uint32 flags) override;
    void destroiJanela(SDL_Window* window) override;
    SDL_Renderer* criaRenderer(SDL_Window* window, int index, Uint32 flags) override;
    void destroiRenderer(SDL_Renderer* renderer) override;
    void defineCor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a) override;
    void limpaRenderer(SDL_Renderer* renderer) override;
    void renderPresent(SDL_Renderer* renderer) override;
    void criaJogador(b2World* world, SDL_Renderer* renderer, float x, float y) override;
    void destroiJogador() override;
    void renderJogador(float x, float y) override;

private:
    SDL_Window* janela;
    SDL_Renderer* renderizador;
    b2Body* jogadorCorpo;
};
