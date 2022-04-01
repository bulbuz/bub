#include "Player.h"

Player::Player() {
	mVelX = 0;
	mVelY = 0;

	playerRect.x = 50;
	playerRect.y = 50;
	playerRect.w = WIDTH;
	playerRect.h = HEIGHT;
}

void Player::update() {
	move();
}

void Player::handleEvent(SDL_Event& event) {
	if(event.type == SDL_KEYDOWN /*&& event.key.repeat == 0*/) {
		switch(event.key.keysym.sym) {
			case SDLK_LEFT:
				mVelX -= VEL;
				break;
			
			case SDLK_RIGHT:
				mVelX += VEL;
				break;

			case SDLK_UP:
				mVelY -= VEL;
				break;

			case SDLK_DOWN:
				mVelY += VEL;
				break;

			default:
				break;
		}
	}
}

void Player::move() {
	playerRect.x = mVelX;
	playerRect.y = mVelY;
}

void Player::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &playerRect);
}
