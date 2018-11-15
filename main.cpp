#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "cGame.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define NB_GAME_OBJECTS 1

int main(int argc, char * argv[])
{   
	//Game instance creation
	cGame currentGame("New SDL Game", SCREEN_WIDTH, SCREEN_HEIGHT);

	//If the game hasn't been initialized successfully, it returns an error with exit code.
	if (currentGame.GetGameState() == Corrupted)
	{
		std::cout << "[Fatal Error] Failed to initialize the game, refer to the SDL logs." << std::endl;
		return EXIT_FAILURE;
	}
	std::cout << "[Log info] Game instance successfully initialized." << std::endl;
	//Otherwise the game environment is started and will follow its game loop rules.
	currentGame.ClearScreen();
	currentGame.StartGame(NB_GAME_OBJECTS);

	return EXIT_SUCCESS;
}