#include "Texture.h"

Texture::Texture() {
	texture = NULL;
	width = 0;
	height = 0;
}

bool Texture::load(std::string path, SDL_Renderer* renderer) {
	free();

	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == NULL) {
		std::cout << "Could not load image! " << path.c_str() << " SDL_image Error: " << IMG_GetError() << std::endl;
	} else {
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0xFF, 0xFF, 0xFF ) );

		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if(newTexture == NULL) {
			std::cout << "Could create load image! " << path.c_str() << " SDL_image Error: " << IMG_GetError() << std::endl;
		} else {
			width = loadedSurface->w;
			height = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}
	texture = newTexture;
	return texture != NULL;
}

void Texture::free() {
	if(texture != NULL) {
		SDL_DestroyTexture(texture);
		texture = NULL;
		width = 0;
		height = 0;
	}
}

void Texture::render(SDL_Renderer* renderer, int x, int y) {
	SDL_Rect renderQuad = { x, y, width, height };
	SDL_RenderCopy(renderer, texture,  NULL, &renderQuad);
}

int Texture::getWidth() {
	return width;
}

int Texture::getHeight() {
	return height;
}

Texture::~Texture() {
	free();
}
