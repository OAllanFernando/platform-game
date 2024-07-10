// Jogador.hpp
#pragma once
#include "Interface.hpp"
#include <Box2D/Box2D.h>
#include "Teclas.hpp"

class Jogador {
public:
    Jogador(b2World* world, Interface* interface, float x, float y);

    void tecla(Key key);
    void render();


private:
    b2World* m_world;
    b2Body* m_jogadorCorpo;
    Interface* m_interface;
    void setX(float x);
    void setY(float y);
    float getX();
    float getY();
};
