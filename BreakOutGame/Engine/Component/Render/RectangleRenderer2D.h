#pragma once
#include "GameRenderer.h"
class RectangleRenderer2D :public GameRenderer
{

public:

	using GameRenderer::GameRenderer;

	virtual void Render(SDL_Renderer* renderer) const;
};

