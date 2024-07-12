#include "Chao.hpp"
#include <iostream>

Chao::Chao(b2World* world, Interface* interface, float x, float y, float width, float height)
    : m_world(world), m_interface(interface), m_width(width), m_height(height) {
    // Defina as propriedades do chão
    b2BodyDef groundBodyDef;
    groundBodyDef.type = b2_staticBody;
    groundBodyDef.position.Set(x, y);
    m_chaoCorpo = m_world->CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;
    //fixture definition
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &groundBox;

    groundBox.SetAsBox(width, 1, b2Vec2(0, 0), 0);//ground
    m_chaoCorpo->CreateFixture(&myFixtureDef);
    std::cout << "Posição do chão: (" << m_chaoCorpo->GetPosition().x << ", " << m_chaoCorpo->GetPosition().y << ")" << std::endl;

    groundBox.SetAsBox(width, 1, b2Vec2(0, 40), 0);//ceiling
    m_chaoCorpo->CreateFixture(&myFixtureDef);
    std::cout << "Posição do teto: (" << m_chaoCorpo->GetPosition().x << ", " << m_chaoCorpo->GetPosition().y << ")" << std::endl;

    groundBox.SetAsBox(1, 20, b2Vec2(-20, 20), 0);//left wall
    m_chaoCorpo->CreateFixture(&myFixtureDef);
    std::cout << "Posição da parede esquerda: (" << m_chaoCorpo->GetPosition().x << ", " << m_chaoCorpo->GetPosition().y << ")" << std::endl;

    groundBox.SetAsBox(1, 20, b2Vec2(20, 20), 0);//right wall
    m_chaoCorpo->CreateFixture(&myFixtureDef);
    std::cout << "Posição da parede direita: (" << m_chaoCorpo->GetPosition().x << ", " << m_chaoCorpo->GetPosition().y << ")" << std::endl;

    std::cout << std::endl;
}

void Chao::render() {
    if (m_interface != nullptr) {
        float x = m_chaoCorpo->GetPosition().x;
        float y = m_chaoCorpo->GetPosition().y;

        m_interface->renderChao(x, y, m_width, m_height);
    }
    else {
        std::cerr << "Erro: Interface gráfica não inicializada" << std::endl;
    }
}
