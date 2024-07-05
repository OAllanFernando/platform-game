#pragma once

#include "Game.hpp"

class Rect {
public: 
	Rect(const Game& game, int w, int h, int x, int y, int r, int g, int b, int a);
	void draw() const;
	void pollEvents();

private:
	int _w, _h;
	int	_x, _y;
	int	_r, _g, _b, _a;
};