
#ifndef Interface_HPP
#define Interface_HPP
#include <Box2D/Box2D.h>

#include <SDL.h>

class Interface {
public:
    virtual ~Interface() {}
    virtual SDL_Window* criaJanela(const char* title, int x, int y, int w, int h, Uint32 flags) = 0;
 
    virtual void destroiJanela(SDL_Window* window) = 0;
    virtual SDL_Renderer* criaRenderer(SDL_Window* window, int index, Uint32 flags) = 0;
    virtual void destroiRenderer(SDL_Renderer* renderer) = 0;
    virtual void defineCor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a) = 0;
    virtual void limpaRenderer(SDL_Renderer* renderer) = 0;
    virtual void renderPresent(SDL_Renderer* renderer) = 0;



    // jogador
    virtual void criaJogador(b2World* world, SDL_Renderer* renderer, float x, float y) = 0;
    virtual void destroiJogador() = 0;
    virtual void renderJogador(float x, float y) = 0;
};

 
#endif