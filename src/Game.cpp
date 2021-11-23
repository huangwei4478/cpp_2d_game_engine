#include "Game.h"
#include <iostream>
#include <SDL.h>

Game::Game() {
	isRunning = false;
	std::cout << "Game constructor called!" << std::endl;
}

Game::~Game() {
	std::cout << "Game destructor called!" << std::endl;
}

void Game::Initialize() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) 	{
		std::cerr << "Error initializing SDL." << std::endl;
		return;
	}

	SDL_DisplayMode displayMode;
	SDL_GetCurrentDisplayMode(0, &displayMode);
	windowWidth = displayMode.w;
	windowHeight = displayMode.h;

	window = SDL_CreateWindow("My Game Engine", 
							  SDL_WINDOWPOS_CENTERED, 
							  SDL_WINDOWPOS_CENTERED, 
							  800,
							  600,
							  SDL_WINDOW_FULLSCREEN);

	if (!window) {
		std::cerr << "Error creating SDL window." << std::endl;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		std::cerr << "Error creating SDL renderer." << std::endl;
	}

	isRunning = true;
}

void Game::Run() {
	while (isRunning == true) {
		ProcessInput();
		Update();
		Render();
	}
}

void Game::ProcessInput() {
	SDL_Event sdlEvent;

	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			if (sdlEvent.key.keysym.sym == SDLK_ESCAPE) {
				isRunning = false;
			}
			break;
		}
	}
}

void Game::Update() {
}

void Game::Render() {
}

void Game::Destroy() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	renderer = nullptr;
	window = nullptr;
	SDL_Quit();
}
