#include "CoreClass.h"

uint32_t Object::GetId()
{
	return objectID;
}

void Object::SetId(uint32_t id)
{
	objectID = id;
}

void GameComponent::SetMyEntity(GameEntity& gameEntity)
{
	myGameEntity = gameEntity;
}

void GameEntity::ChangePosition(int x, int y)
{
	transform.x = x;
	transform.y = y;
}

void GameEntity::OnCollisionEnter(GameComponent* otherCollider)
{

}

void GameEntity::OnTriggerEnter(GameComponent* otherCollider)
{

}

void GameEntity::DestroySelf()
{
	for (GameComponent* myComponent : myComponents)
	{
		myComponent->DestroySelf();
	}
	//GameEntityManager::GetInstance().DeleteGameEntity(entityId);
}