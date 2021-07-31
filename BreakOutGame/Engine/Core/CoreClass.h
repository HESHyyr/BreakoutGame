#pragma once
#include <vector>
#include <SDL.h>

using namespace std;

class GameEntity;

class Object
{

public:

	uint32_t GetId();

	virtual void SetId(uint32_t id);

	//Game Logic
	virtual void Update(float timePerFrame) const = 0;

protected:

	//Only some Components will use ID for tracking
	uint32_t objectID;

};

class GameComponent : public Object
{

public:

	GameEntity& myGameEntity;
	bool isActive;

	GameComponent(GameEntity& gameEntity)
		: myGameEntity(gameEntity)
	{}

	//Virtual destructor for polymorphism
	virtual ~GameComponent() {};

	void SetMyEntity(GameEntity& gameEntity);

	void SetActive(bool active) { isActive = active; }
	virtual void DestroySelf() = 0;


};

class GameEntity : public Object
{
public:

	SDL_Rect transform;
	char* tag;
	vector<GameComponent*> myComponents;

	void ChangePosition(int x, int y);

	virtual void OnCollisionEnter(GameComponent* otherCollider);
	virtual void OnTriggerEnter(GameComponent* otherCollider);

	void DestroySelf();

};
