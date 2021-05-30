#pragma once
#include "GameManager/SDLManager.h"
#include "Component/GameComponent.h"
#include <vector>

using namespace std;

struct Color
{
	Uint8 r, g, b, a;
};

class GameRenderer: GameComponent
{

public:

	Color color;
	SDL_Rect& objectTransform;

	GameRenderer(vector<GameRenderer*> &mainRendererList , SDL_Rect& transformReference);

	void ChangeColor(Color color);
	virtual void Render(SDL_Renderer* renderer) const;
	virtual void DestroySelf() override;

private:

	vector<GameRenderer*> &rendererList;
};