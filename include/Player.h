#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Utils.h"

class Player {
	public:
		Player();
		void handleEvent(SDL_Event& event);
		void update();
		void render(SDL_Renderer* renderer);
		
		static const int WIDTH = 100;
		static const int HEIGHT = 100;
		static const int VEL = 8;

	private:
		void move();

		double VelX, VelY;
		bool right, left, down, up;
		SDL_Rect playerRect;
};
