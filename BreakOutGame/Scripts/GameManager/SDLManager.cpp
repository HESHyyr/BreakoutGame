#include "SDLManager.h"

bool SDLManager::SDLInit() 
{
	bool success = true;

	myWindow = unique_ptr<SDL_Window, SDL_Deleters>(
		SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, windowWidth, windowHeight, SDL_WINDOW_SHOWN),
		SDL_Deleters());

	if (myWindow == nullptr)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else 
	{
		//Create Renderer
		myRenderer = std::unique_ptr<SDL_Renderer, SDL_Deleters>(SDL_CreateRenderer(myWindow.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC), SDL_Deleters());
		if (myRenderer == nullptr)
		{
			printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			if ((IMG_Init(imageFlags) & imageFlags) != imageFlags)
				printf("SDL_image could not initialize!SDL_image Error : %s\n", IMG_GetError());
		}
	}

	return success;
}