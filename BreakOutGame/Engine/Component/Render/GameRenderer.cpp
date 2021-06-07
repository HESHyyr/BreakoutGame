#include <algorithm>

#include "GameRenderer.h"

GameRenderer::GameRenderer(GameEntity& gameEntity, unordered_set<GameRenderer*> &mainRendererList)
	:rendererList(mainRendererList), GameComponent::GameComponent(gameEntity)
{
	mainRendererList.insert(this);
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
	rendererList.erase(this);
}