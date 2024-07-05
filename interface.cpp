// interface.cpp
#include "interface.hpp"
#include <iostream> 
void Interface::apertaTeclas() {
	std::cout << "pracima" << std::endl;
};
    
void Interface::processarEventos() {
    SDL_Event event;
	
	while (SDL_PollEvent(&event)) {

		switch (event.type) {
		case SDL_QUIT:
			exit(0);
			break;
		}
	};
};


