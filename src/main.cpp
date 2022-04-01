#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Game.h"

int main(int argc, char* args[]) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << "Could not initialize SDL! SDL_Error: " << SDL_GetError() << std::endl;

	if (!IMG_Init(IMG_INIT_PNG))
		std::cout << "Could not initialize SDL_image! SDL_Error: " << SDL_GetError() << std::endl;

	Game game;
	game.run();	

	return 0;
}
