#pragma once

#include <SDL.h>


class Game {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning;
	int windowWidth;
	int windowHeight;
public:
	Game();
	~Game();
	void Initialize();
	void Run();
	void ProcessInput();
	void Update();
	void Render();
	void Destroy();
};

