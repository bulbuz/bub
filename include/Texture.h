#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class Texture {
	public:
		Texture();
		~Texture();

		bool load(std::string path);
		void free();
		void render();
		int getWidth();
		int getHeight();

	private:
		SDL_Texture* tex;

		int mWidth;
		int mHeight;
};
