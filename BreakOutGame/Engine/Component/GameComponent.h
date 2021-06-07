#pragma once
#include "GameEntity/GameEntity.h"

using namespace std;

class GameEntity;

class GameComponent
{

public:

	GameEntity& myGameEntity;

	GameComponent(GameEntity& gameEntity)
		:myGameEntity(gameEntity)
	{ };

	void SetActive(bool active) { isActive = active; }
	virtual void DestroySelf() = 0;

protected:

	bool isActive;

};