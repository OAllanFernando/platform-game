#ifndef CHAO_HPP
#define CHAO_HPP

#include "Interface.hpp"
#include <Box2D/Box2D.h>


class Chao {
public:
    Chao(b2World* world, Interface* interface, float x, float y, float width, float height);

    void render();

private:
    b2World* m_world;
    b2Body* m_chaoCorpo;
    Interface* m_interface;
    float m_width;
    float m_height;

};

#endif /* GROUND_HPP */