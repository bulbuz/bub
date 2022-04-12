#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

#include "Player.h"

class Game {
	public:
		Game();
		~Game();
		void run();

	private:
		void render();
		void update();
		void events();

		static const int SCREEN_WIDTH = 1280;
		static const int SCREEN_HEIGHT = 720;
		const char* TITLE;
		SDL_Window* window;
		SDL_Renderer* renderer;
		bool running;
		Player player;
};
