#include "SdlInterfaceImpl.hpp"

SdlInterfaceImpl::SdlInterfaceImpl() : janela(nullptr), renderizador(nullptr) {}



// sdl para renderização da janela

void SdlInterfaceImpl::criaJanela(const char* title, int x, int y, int w, int h, Uint32 flags) {
    janela = SDL_CreateWindow(title, x, y, w, h, flags);
}

void SdlInterfaceImpl::destroiJanela() {
    if (janela) {
        SDL_DestroyWindow(janela);
        janela = nullptr;
    }
}

void SdlInterfaceImpl::criaRenderer(int index, Uint32 flags) {
    renderizador = SDL_CreateRenderer(janela, index, flags);
}

void SdlInterfaceImpl::destroiRenderer() {
    if (renderizador) {
        SDL_DestroyRenderer(renderizador);
        renderizador = nullptr;
    }
}

void SdlInterfaceImpl::defineCor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(renderizador, r, g, b, a);
}

void SdlInterfaceImpl::limpaRenderer() {
    SDL_RenderClear(renderizador);
}

void SdlInterfaceImpl::renderPresent() {
    SDL_RenderPresent(renderizador);
} 

bool SdlInterfaceImpl::janelaValida() {
    return janela != nullptr;
}

bool SdlInterfaceImpl::rendererValido() {
    return renderizador != nullptr;
}


// jogador

void SdlInterfaceImpl::criaJogador(b2World* world, float x, float y) {
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


// renderizadores do chao

void SdlInterfaceImpl::criaChao(b2World* world, float x, float y, float w, float h) {
	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(x, y);
    chaoCorpo = world->CreateBody(&bodyDef);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(w, h);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 1;
	fixtureDef.friction = 0.3f;
    chaoCorpo->CreateFixture(&fixtureDef);
}

void SdlInterfaceImpl::destroiChao() {
	if (chaoCorpo != nullptr) {
		chaoCorpo->GetWorld()->DestroyBody(chaoCorpo);
		chaoCorpo = nullptr;
	}
}

void SdlInterfaceImpl::renderChao(float x, float y, float w, float h) {
	// Calcula as coordenadas de renderização (convertendo metros para pixels)
	int chaoX = static_cast<int>(x);
	int chaoY = static_cast<int>(y);
	int chaoWidthPixels = static_cast<int>(w);
	int chaoHeightPixels = static_cast<int>(h);

	SDL_Rect chaoRect = { chaoX, chaoY, chaoWidthPixels, chaoHeightPixels };
	SDL_RenderFillRect(renderizador, &chaoRect);
}


void SdlInterfaceImpl::moveJogadorFrente() {
    if (jogadorCorpo != nullptr) {
		b2Vec2 vel = jogadorCorpo->GetLinearVelocity();
		vel.x = 1000;
		jogadorCorpo->SetLinearVelocity(vel);
	}
}

void SdlInterfaceImpl::moveJogadorTras() {
    if (jogadorCorpo != nullptr) {
		b2Vec2 vel = jogadorCorpo->GetLinearVelocity();
		vel.x = -10;
		jogadorCorpo->SetLinearVelocity(vel);
	}
}

void SdlInterfaceImpl::moveJogadorPulo() {
    if (jogadorCorpo != nullptr) {
		b2Vec2 vel = jogadorCorpo->GetLinearVelocity();
		vel.y = -10;
		jogadorCorpo->SetLinearVelocity(vel);
	}
}

//eventos+teclas
bool SdlInterfaceImpl::pollEvent(Key& key) {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            key = Key::QUIT;
        }
        else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
            case SDLK_UP:
                key = Key::UP;
                break;
            case SDLK_DOWN:
                key = Key::DOWN;
                break;
            case SDLK_LEFT:
                key = Key::LEFT;
                break;
            case SDLK_RIGHT:
                key = Key::RIGHT;
                break;
            default:
                key = Key::NONE;
                break;
            }
        }
        return true;
    }
    return false;
}