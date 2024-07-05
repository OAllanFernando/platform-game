// SdlInterfaceImpl.cpp
#include "SdlInterfaceImpl.hpp"
#include <iostream>
SdlInterfaceImpl::SdlInterfaceImpl() : janela(nullptr), renderizador(nullptr) {

}

SDL_Window* SdlInterfaceImpl::criaJanela(const char* title, int x, int y, int w, int h, Uint32 flags) {
    std::cout << "pasoooooooooooooo: " << std::endl;
    janela = SDL_CreateWindow(title, x, y, w, h, flags);
    return janela;
}

void SdlInterfaceImpl::destroiJanela(SDL_Window* window) {
    if (window != nullptr) {
        SDL_DestroyWindow(window);
        janela = nullptr;
    }
}

SDL_Renderer* SdlInterfaceImpl::criaRenderer(SDL_Window* window, int index, Uint32 flags) {
    if (window != nullptr) {
        renderizador = SDL_CreateRenderer(window, index, flags);
    }
    return renderizador;
}

void SdlInterfaceImpl::destroiRenderer(SDL_Renderer* renderer) {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
        renderizador = nullptr;
    }
}

void SdlInterfaceImpl::defineCor(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void SdlInterfaceImpl::limpaRenderer(SDL_Renderer* renderer) {
    SDL_RenderClear(renderer);
}

void SdlInterfaceImpl::renderPresent(SDL_Renderer* renderer) {
    SDL_RenderPresent(renderer);
}


void SdlInterfaceImpl::criaJogador(b2World* world, SDL_Renderer* renderer, float x, float y) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(x, y);
    bodyDef.angle = 0;
    jogadorCorpo = world->CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(10.0f, 10.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1;
    fixtureDef.friction = 0.3f;
    jogadorCorpo->CreateFixture(&fixtureDef);
}

void SdlInterfaceImpl::destroiJogador() {
    if (jogadorCorpo != nullptr) {
        jogadorCorpo->GetWorld()->DestroyBody(jogadorCorpo);
        jogadorCorpo = nullptr;
    }
}

void SdlInterfaceImpl::renderJogador(float x, float y) {
    std::cout << "jogadorPosicao:  " << x << std::endl;

        std::cout << "jogadorPffffffffffffosicao: " << std::endl;
      
        float jogadorWidth = 10.0f; // Supondo que seja 2 metros
        float jogadorHeight = 10.0f; // Supondo que seja 2 metros

        // Calcula as coordenadas de renderização (convertendo metros para pixels)
        int jogadorX = static_cast<int>(x);
        int jogadorY = static_cast<int>(y);
        int jogadorWidthPixels = static_cast<int>(jogadorWidth);
        int jogadorHeightPixels = static_cast<int>(jogadorHeight);


        SDL_Rect jogadorRect = { jogadorX, jogadorY, jogadorWidthPixels, jogadorHeightPixels };
        SDL_RenderFillRect(renderizador, &jogadorRect);
}
