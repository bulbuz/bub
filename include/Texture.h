#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>

class Texture {
	public:
		Texture();
		~Texture();

		bool load(std::string path, SDL_Renderer* renderer);
		void free();
		void render(SDL_Renderer* renderer, int x, int y);
		int getWidth();
		int getHeight();

	private:
		SDL_Texture* texture;

		int width;
		int height;
};
