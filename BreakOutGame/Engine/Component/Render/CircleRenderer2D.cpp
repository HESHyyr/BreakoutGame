#include "CircleRenderer2D.h"

void  CircleRenderer2D::Render(SDL_Renderer* renderer) const
{
	GameRenderer::Render(renderer);
	
	//Midpoint Algorithm On how to draw a Circle
	//https://en.wikipedia.org/wiki/Midpoint_circle_algorithm#C_Example
	//https://stackoverflow.com/questions/38334081/howto-draw-circles-arcs-and-vector-graphics-in-sdl

	const int32_t diameter = (GameComponent::myGameEntity.transform.w * 2);

	int32_t x = (GameComponent::myGameEntity.transform.w - 1);
	int32_t y = 0;
	int32_t tx = 1;
	int32_t ty = 1;
	int32_t error = (tx - diameter);

	while (x >= y)
	{
		//  Each of the following renders an octant of the circle
		SDL_RenderDrawPoint(renderer, GameComponent::myGameEntity.transform.x + x, GameComponent::myGameEntity.transform.y - y);
		SDL_RenderDrawPoint(renderer, GameComponent::myGameEntity.transform.x + x, GameComponent::myGameEntity.transform.y + y);
		SDL_RenderDrawPoint(renderer, GameComponent::myGameEntity.transform.x - x, GameComponent::myGameEntity.transform.y - y);
		SDL_RenderDrawPoint(renderer, GameComponent::myGameEntity.transform.x - x, GameComponent::myGameEntity.transform.y + y);
		SDL_RenderDrawPoint(renderer, GameComponent::myGameEntity.transform.x + y, GameComponent::myGameEntity.transform.y - x);
		SDL_RenderDrawPoint(renderer, GameComponent::myGameEntity.transform.x + y, GameComponent::myGameEntity.transform.y + x);
		SDL_RenderDrawPoint(renderer, GameComponent::myGameEntity.transform.x - y, GameComponent::myGameEntity.transform.y - x);
		SDL_RenderDrawPoint(renderer, GameComponent::myGameEntity.transform.x - y, GameComponent::myGameEntity.transform.y + x);

		if (error <= 0)
		{
			++y;
			error += ty;
			ty += 2;
		}

		if (error > 0)
		{
			--x;
			tx += 2;
			error += (tx - diameter);
		}
	}

}