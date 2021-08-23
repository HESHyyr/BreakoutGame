#pragma once
#include <vector>
#include <SDL.h>

using namespace std;

class GameEntity;

class Object
{

public:

	uint32_t GetId() const;

	virtual void SetId(uint32_t id);

	//Game Logic
	virtual void Update(float timePerFrame) = 0;
	virtual void DestroySelf() = 0;

protected:

	uint32_t objectID;

};

class GameComponent : public Object
{

public:

	//Virtual destructor for polymorphism
	virtual ~GameComponent() {};

	void SetMyEntity(GameEntity* gameEntity);
	void SetActive(bool active) { isActive = active; }

	virtual void Update(float timePerFrame) override {};
	virtual void DestroySelf() override;

	GameEntity* myGameEntity;
	bool isActive;

};

class GameEntity : public Object
{
public:

	//Virtual destructor for polymorphism
	virtual ~GameEntity() {};

	void ChangePosition(int x, int y);

	virtual void OnCollisionEnter(GameComponent* otherCollider) {};
	virtual void OnTriggerEnter(GameComponent* otherCollider) {};

	virtual void Update(float timePerFrame) override {};
	virtual void DestroySelf() override;


	SDL_Rect transform;
	char* tag;
	vector<GameComponent*> myComponents;
};
