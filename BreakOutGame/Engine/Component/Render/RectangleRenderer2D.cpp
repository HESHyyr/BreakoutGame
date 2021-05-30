#include "RectangleRenderer2D.h"

void RectangleRenderer2D::Render(SDL_Renderer* renderer) const 
{
	GameRenderer::Render(renderer);
	SDL_RenderFillRect(renderer, &objectTransform);
} 