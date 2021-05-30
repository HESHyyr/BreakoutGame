#pragma once
#include "GameRenderer.h"
class CircleRenderer2D :public GameRenderer
{

public:

	using GameRenderer::GameRenderer;

	virtual void Render(SDL_Renderer* renderer) const;
};