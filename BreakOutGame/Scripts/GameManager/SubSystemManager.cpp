#include "SubSystemManager.h"
#include <SDL.h>
#include <iostream>

using namespace std;

SubSystemManager::~SubSystemManager()
{
	SDL_Quit();
}

bool SubSystemManager::InitSubSystems()
{
	bool initSuccess = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		initSuccess = false;
		cout << "Subsystem cannot initialize, SDL_Error: " << SDL_GetError() << endl;
	}

	return initSuccess;
}
