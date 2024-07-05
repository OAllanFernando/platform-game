#include "implementacaoSdl.hpp"

void ImplementacaoSdl::apertaTeclas()
{
	std::cout << "pracima" << std::endl;
};

void ImplementacaoSdl::processarEventos()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {

		switch (event.type) {
		case SDL_QUIT:
			exit(0);
			break;
		}
	};
};

void ImplementacaoSdl::criarJogador()
{
};

void ImplementacaoSdl::criarChao()
{
};

void ImplementacaoSdl::criarInimigo()
{
};

void ImplementacaoSdl::criarFundo()
{
};

void ImplementacaoSdl::criarTiro()
{
};

void ImplementacaoSdl::criarPlacar()
{
};

void ImplementacaoSdl::criarVida()
{
};

void ImplementacaoSdl::criaJanela()
{
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Minhoca", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	SDL_Delay(2000);

	SDL_DestroyWindow(window);
	SDL_Quit();	
};

