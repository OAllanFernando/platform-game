#ifndef Interface_HPP
#define Interface_HPP
#include <Box2D/Box2D.h>
#include "Teclas.hpp"
#include <SDL.h>

class Interface {
public:
    virtual ~Interface() {}
    virtual void criaJanela(const char* title, int x, int y, int w, int h, Uint32 flags) = 0;
    virtual void destroiJanela() = 0;
    virtual void criaRenderer(int index, Uint32 flags) = 0;
    virtual void destroiRenderer() = 0;
    virtual void defineCor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) = 0;
    virtual void limpaRenderer() = 0;
    virtual void renderPresent() = 0;
    virtual bool janelaValida() = 0;
    virtual bool rendererValido() = 0;

    // jogador
    virtual void criaJogador(b2World* world, float x, float y) = 0;
    virtual void destroiJogador() = 0;
    virtual void renderJogador(float x, float y) = 0;

    // chao
    virtual void criaChao(b2World* world, float x, float y, float w, float h) = 0;
    virtual void destroiChao() = 0;
    virtual void renderChao(float x, float y, float w, float h) = 0;

    // eventos
    virtual bool pollEvent(Key& key) = 0;
    

};

#endif
