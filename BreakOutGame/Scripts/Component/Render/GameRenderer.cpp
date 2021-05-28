#include <algorithm>

#include "GameRenderer.h"

GameRenderer::GameRenderer(vector<GameRenderer*> &mainRendererList, SDL_Rect& transformReference)
	:rendererList(mainRendererList), objectTransform(transformReference)
{
	mainRendererList.push_back(this);
}

void GameRenderer::ChangeColor(Color color)
{
	this->color = color;
}

void GameRenderer::Render(SDL_Renderer* renderer) const
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void GameRenderer::DestroySelf()
{
	//Not using Erase–remove idiom, cause all values should be unique
	//https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom

	vector<GameRenderer*>::iterator myIterator;
	for (myIterator = rendererList.begin(); myIterator < rendererList.end(); myIterator++) {
		if (*myIterator == this)
			break;
	}
	rendererList.erase(myIterator);
}