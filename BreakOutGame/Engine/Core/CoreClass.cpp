#include "CoreClass.h"

#include <GameManager/ObjectManager.h>

uint32_t Object::GetId() const
{
	return objectID;
}

void Object::SetId(uint32_t id)
{
	objectID = id;
}

void GameComponent::SetMyEntity(GameEntity* gameEntity)
{
	myGameEntity = gameEntity;
}

void GameComponent::DestroySelf()
{
	ObjectManager::GetInstance().DeleteObject(objectID);
}

void GameEntity::ChangePosition(int x, int y)
{
	transform.x = x;
	transform.y = y;
}

void GameEntity::DestroySelf()
{
	for (GameComponent* myComponent : myComponents)
	{
		myComponent->DestroySelf();
	}
	ObjectManager::GetInstance().DeleteObject(objectID);
}