#pragma once

#include <unordered_set>

#include <Core/CoreClass.h>
#include <GameManager/SDLManager.h>
#include <Utility/DataStructures/Color.h>


class GameRenderer: public GameComponent
{

public:

	GameRenderer();

	void ChangeColor(const Color& color);
	virtual void Render(SDL_Renderer* renderer) const;
	virtual void DestroySelf() override;


	Color color;
};