#pragma once
#include "Interface.hpp"
#include <Box2D/Box2D.h>
#include "Teclas.hpp"

class SdlInterfaceImpl : public Interface {
public:
    SdlInterfaceImpl();
    void criaJanela(const char* title, int x, int y, int w, int h, Uint32 flags) override;
    void destroiJanela() override;
    void criaRenderer(int index, Uint32 flags) override;
    void destroiRenderer() override;
    void defineCor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) override;
    void limpaRenderer() override;
    void renderPresent() override;
    bool janelaValida() override;
    bool rendererValido() override;

    // jogador
    void criaJogador(b2World* world, float x, float y) override;
    void destroiJogador() override;
    void renderJogador(float x, float y) override;
   // bool colisaoChao(float x, float y) override;


    // chao
    void criaChao(b2World* world, float x, float y, float w, float h) override;
    void destroiChao() override;
    void renderChao(float x, float y, float w, float h) override;

    // eventos
    bool pollEvent(Key& key) override;

private:
    SDL_Window* janela;
    SDL_Renderer* renderizador;
    b2Body* jogadorCorpo;
    b2Body* chaoCorpo;
};
