#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Player {
	public:
		Player();
		void handleEvent(SDL_Event& event);
		void update();
		void render(SDL_Renderer* renderer);
		
		static const int WIDTH = 20;
		static const int HEIGHT = 20;
		static const int VEL = 10;

	private:
		void move();

		int mPosX, mPosY;
		int mVelX, mVelY;
		SDL_Rect playerRect;
};
