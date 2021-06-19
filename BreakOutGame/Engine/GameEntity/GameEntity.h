#pragma once

#include <SDL.h>
#include <unordered_set>
#include <string>

#include "Component/GameComponent.h"

using namespace std;

class GameComponent;

class GameEntity
{
public:

	SDL_Rect transform;
	string tag;
	unordered_set<GameComponent*> myComponents;

	template<class T>
	static GameEntity* CreateGameEntity() { return new T(); };

	void ChangePosition(int x, int y);

	virtual void OnCollisionEnter(GameComponent* otherCollider);
	virtual void OnTriggerEnter(GameComponent* otherCollider);

	void DestroySelf();
};
