#include "GameRenderer.h"

#include <GameManager/RenderManager.h>

GameRenderer::GameRenderer()
{
	RenderManager::GetInstance().RenderQueue.insert(this);
}

void GameRenderer::ChangeColor(const Color& color)
{
	this->color = color;
}

void GameRenderer::Render(SDL_Renderer* renderer) const
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

void GameRenderer::DestroySelf()
{
	RenderManager::GetInstance().RenderQueue.erase(this);
}