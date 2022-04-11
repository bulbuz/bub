#include "Player.h"

Player::Player() {
	VelX = 0;
	VelY = 0;

	playerRect.x = 50;
	playerRect.y = 50;
	playerRect.w = WIDTH;
	playerRect.h = HEIGHT;

	right = 0;
	left = 0;
	up = 0;
	down = 0;
}

void Player::update() {
	move();
}

void Player::handleEvent(SDL_Event& event) {
	if(event.type == SDL_KEYDOWN && event.key.repeat == 0) {
		switch(event.key.keysym.sym) {
			case SDLK_LEFT:
				left = 1;
				break;
			
			case SDLK_RIGHT:
				right = 1;
				break;

			case SDLK_UP:
				up = 1;
				break;

			case SDLK_DOWN:
				down = 1;	
				break;

			default:
				break;
		}
	}

	if(event.type == SDL_KEYUP && event.key.repeat == 0) {
		switch(event.key.keysym.sym) {
			case SDLK_LEFT:
				left = 0;
				break;
			case SDLK_RIGHT:
				right = 0;
				break;
			case SDLK_UP:
				up = 0;
				break;
			case SDLK_DOWN:
				down = 0;
				break;
		}
	}
}

void Player::move() {
	VelX = 0, VelY = 0;

	if(right && !left)
		VelX = VEL;

	if(left && !right)
		VelX = -VEL;

	if(up && !down)
		VelY = -VEL;

	if(down && !up)
		VelY = VEL;
	
	// Calculate correct diagonal speed
	if(VelX && VelY) {
		VelX /= sqrt(2);
		VelY /= sqrt(2);
	}

	playerRect.x += VelX;
	playerRect.y += VelY;
}

void Player::render(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &playerRect);
}
