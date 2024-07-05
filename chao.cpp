#include "Chao.hpp"
#include <iostream>

Chao::Chao(b2World* world, SDL_Renderer* renderer, float x, float y, float width, float height)
    : m_world(world), m_renderer(renderer) {
    // Defina as propriedades do chão
    b2BodyDef groundBodyDef;
    groundBodyDef.type = b2_staticBody;
    groundBodyDef.position.Set(x, y);
    m_chaoBody = m_world->CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;

    //fixture definition
    b2FixtureDef myFixtureDef;
    myFixtureDef.shape = &groundBox;


    //add four walls to the static body
    groundBox.SetAsBox(600, 1, b2Vec2(0, 0), 0);//ground
    m_chaoBody->CreateFixture(&myFixtureDef);
    std::cout << "Posição do chão: (" << m_chaoBody->GetPosition().x << ", " << m_chaoBody->GetPosition().y << ")" << std::endl;

    groundBox.SetAsBox(20, 1, b2Vec2(0, 40), 0);//ceiling
    m_chaoBody->CreateFixture(&myFixtureDef);
    std::cout << "Posição do teto: (" << m_chaoBody->GetPosition().x << ", " << m_chaoBody->GetPosition().y << ")" << std::endl;

    groundBox.SetAsBox(1, 20, b2Vec2(-20, 20), 0);//left wall
    m_chaoBody->CreateFixture(&myFixtureDef);
    std::cout << "Posição da parede esquerda: (" << m_chaoBody->GetPosition().x << ", " << m_chaoBody->GetPosition().y << ")" << std::endl;

    groundBox.SetAsBox(1, 20, b2Vec2(20, 20), 0);//right wall
    m_chaoBody->CreateFixture(&myFixtureDef);
    std::cout << "Posição da parede direita: (" << m_chaoBody->GetPosition().x << ", " << m_chaoBody->GetPosition().y << ")" << std::endl;

    std::cout << std::endl;
}

void Chao::render() {
    // Render the ground, ceiling, and walls
    SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255); // Set color to white

    // Ground
    SDL_Rect groundRect = { static_cast<int>(m_chaoBody->GetPosition().x - 300), static_cast<int>(m_chaoBody->GetPosition().y - 1), 600, 2 };
    SDL_RenderFillRect(m_renderer, &groundRect);

    // Ceiling
    SDL_Rect ceilingRect = { static_cast<int>(m_chaoBody->GetPosition().x - 300), static_cast<int>(m_chaoBody->GetPosition().y + 39), 600, 2 };
    SDL_RenderFillRect(m_renderer, &ceilingRect);

    // Left Wall
    SDL_Rect leftWallRect = { static_cast<int>(m_chaoBody->GetPosition().x - 300), static_cast<int>(m_chaoBody->GetPosition().y), 2, 40 };
    SDL_RenderFillRect(m_renderer, &leftWallRect);

    // Right Wall
    SDL_Rect rightWallRect = { static_cast<int>(m_chaoBody->GetPosition().x + 300), static_cast<int>(m_chaoBody->GetPosition().y), 2, 40 };
    SDL_RenderFillRect(m_renderer, &rightWallRect);
}
