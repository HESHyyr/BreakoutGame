//Include for CRT library
//Link for documentation https://docs.microsoft.com/en-us/visualstudio/debugger/finding-memory-leaks-using-the-crt-library?view=vs-2019

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <time.h>
#include <crtdbg.h>

#include <GameManager/RenderManager.h>
#include <GameManager/PhysicsManager.h>
#include "GameManager/SubSystemManager.h"
#include "GameManager/SDLManager.h"

using namespace std;

int main(int argc, char *argv[])
{
	//Init RNG
	srand(time(NULL));

	SubSystemManager subSystemManager = SubSystemManager();
	SDLManager sdlManager = SDLManager();


	//To-do: Define Collider Component and add them there

	if (subSystemManager.InitSubSystems()) 
	{
		if (sdlManager.SDLInit()) 
		{
			bool quit = false;
			SDL_Event sdlEvent;

			//Main Game Loop
			while (!quit) {

				//Process Event
				while (SDL_PollEvent(&sdlEvent) != 0) {
					if (sdlEvent.type == SDL_QUIT)
						quit = true;
					else if (sdlEvent.type == SDL_JOYAXISMOTION)
					{
						//Controller Input Handle
						if (sdlEvent.jaxis.which == 0)
						{
							if (sdlEvent.jaxis.axis == 0)
							{

							}
							else if (sdlEvent.jaxis.axis == 1)
							{

							}
						}
					}
				}

				//Update Draw Calls
				SDL_RenderClear(sdlManager.myRenderer.get());

				for(GameRenderer* r: RenderManager::GetInstance().RenderQueue)
					r->Render(sdlManager.myRenderer.get());


				//Update Renderer
				SDL_RenderPresent(sdlManager.myRenderer.get());

			}
		}
	};

	_CrtDumpMemoryLeaks();

	return 0;
}