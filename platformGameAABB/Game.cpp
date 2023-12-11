#include <iostream>
#include "SDL.h"


class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();


	bool running() { return isRunning; }

public:
	bool isRunning;
	SDL_Window* window;
	static SDL_Renderer* renderer;
};


Game::Game()
{}

Game::~Game()
{}



void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
			std::cout << "Subsystem Initialized!..." << std::endl;

			window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
			if (window)
			{
				std::cout << "window created!" << std::endl;
			}

			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				std::cout << "renderer created!" << std::endl;
			}
			isRunning = true;
	}
	else
	{
		isRunning = false;
	}

}

SDL_Rect rect{ 100,100,50,50 };

SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);

int SDL_RenderFillRect(Game::renderer, &rect);

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}

}

void Game::update()
{

}

void Game::render()
{
	SDL_RenderClear(renderer);

	SDL_RenderPresent(Game::renderer);

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
