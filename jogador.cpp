// Jogador.cpp
#include "Jogador.hpp"
#include <iostream>

Jogador::Jogador(b2World* world, Interface* interface, float x, float y)
    : m_world(world), m_interface(interface) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    bodyDef.angle = 0;
    m_jogadorCorpo = m_world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(10.0f, 10.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1;
    fixtureDef.friction = 0.3f;
    m_jogadorCorpo->CreateFixture(&fixtureDef);
}

void Jogador::tecla(Key key) {
    b2Vec2 velocity = m_jogadorCorpo->GetLinearVelocity();
    float speed = 5.0f; // Velocidade do jogador

    switch (key) {
    case Key::UP:
        velocity.y = -speed;
        break;
    case Key::DOWN:
        velocity.y = speed;
        break;
    case Key::LEFT:
        velocity.x = -speed;
        break;
    case Key::RIGHT:
        velocity.x = speed;
        break;
    default:
        break;
    }

    m_jogadorCorpo->SetLinearVelocity(velocity);
}

void Jogador::render() {
    if (m_interface != nullptr) {
        float x = m_jogadorCorpo->GetPosition().x;
        float y = m_jogadorCorpo->GetPosition().y;
        m_interface->renderJogador(x, y);
    }
    else {
        std::cerr << "Erro: Interface gráfica não inicializada" << std::endl;
    }
}

void Jogador::setX(float x) {
    b2Vec2 pos = m_jogadorCorpo->GetPosition();
    pos.x = x;
    m_jogadorCorpo->SetTransform(pos, m_jogadorCorpo->GetAngle());
}

void Jogador::setY(float y) {
    b2Vec2 pos = m_jogadorCorpo->GetPosition();
    pos.y = y;
    m_jogadorCorpo->SetTransform(pos, m_jogadorCorpo->GetAngle());
}

float Jogador::getX() {
    return m_jogadorCorpo->GetPosition().x;
}

float Jogador::getY() {
    return m_jogadorCorpo->GetPosition().y;
}
