#pragma once
#include <SDL.h>
#include <SDL_render.h>
#include <SDL_image.h>
#include <memory>

using namespace std;

// Struct for defining smart pointers custom deleters
struct SDL_Deleters
{
	void operator()(SDL_Window *window) { SDL_DestroyWindow(window); }
	void operator()(SDL_Renderer *renderer) { SDL_DestroyRenderer(renderer); }
	void operator()(SDL_Texture *texture) { SDL_DestroyTexture(texture); }
};

class SDLManager
{

public:
	
	unique_ptr<SDL_Renderer, SDL_Deleters> myRenderer;

	bool SDLInit();


private:

	//SDL Component References
	unique_ptr<SDL_Window, SDL_Deleters> myWindow;


	//Window Size
	int windowWidth = 800;
	int windowHeight = 600;

	//Image flag for what kind of files to load
	int imageFlags = IMG_INIT_PNG;

};