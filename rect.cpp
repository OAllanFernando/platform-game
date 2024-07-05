#include "rect.hpp"

/*Rect::Rect(const Game& game, int w, int h, int x, int y, int r, int g, int b, int a) :
	Game(game), _w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
	{
}

void Rect::draw() const {
	SDL_Rect rect;
	rect.x = _x;
	rect.y = _y;
	rect.w = _w;
	rect.h = _h;
	SDL_SetRenderDrawColor(renderer, 200, 0, 200, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void Rect::pollEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
			case SDLK_UP:
				_y -= 10;
				break;

		}
	default:
		break;
	}
}*/