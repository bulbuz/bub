#include "Game.h"

Game::Game():window(NULL), renderer(NULL) {
	TITLE = "Game";

	window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
		std::cout << "Could not create a window! SDL_Error: " << SDL_GetError() << std::endl;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
		std::cout << "Could not create a renderer! SDL_Error: " << SDL_GetError() << std::endl;

	running = 1;
}

void Game::run() {
	while (running) {
		events();
		update();
		render();
	}
}

void Game::update() {
	player.update();
	SDL_UpdateWindowSurface(window);
}

void Game::render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	player.render(renderer);

	SDL_RenderPresent(renderer);
}

void Game::events() {
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		if(event.type == SDL_QUIT)
			running = 0;
		player.handleEvent(event);
	}
}

Game::~Game() {
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
	std::cout << "Yay! Finished without errors! 😀" << std::endl;
}
