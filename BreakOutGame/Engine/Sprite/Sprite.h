#pragma once
#include <SDL.h>



class Sprite
{
public:

	SDL_Rect transform;

	void ChangePosition(int x, int y);

};

