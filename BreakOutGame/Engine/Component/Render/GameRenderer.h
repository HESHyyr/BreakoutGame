#pragma once

#include <unordered_set>

#include <GameManager/SDLManager.h>
#include <Core/CoreClass.h>


struct Color
{
	Uint8 r, g, b, a;
};

class GameRenderer: public GameComponent
{

public:

	Color color;

	GameRenderer(GameEntity& gameEntity, unordered_set<GameRenderer*> &mainRendererList);

	void ChangeColor(Color color);
	virtual void Render(SDL_Renderer* renderer) const;
	virtual void DestroySelf() override;

private:

	unordered_set<GameRenderer*> &rendererList;
};