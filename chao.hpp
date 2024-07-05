#ifndef CHAO_HPP
#define CHAO_HPP

#include <SDL.h>
#include <Box2D/Box2D.h>

class Chao {
public:
    Chao(b2World* world, SDL_Renderer* renderer, float x, float y, float width, float height);

    void render();

private:
    b2World* m_world;
    SDL_Renderer* m_renderer;
    b2Body* m_chaoBody;
    b2Body* m_groundBody; 
    float m_height;
};

#endif /* GROUND_HPP */