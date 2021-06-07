#include "GameEntity.h"

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
	for(GameComponent* myComponent : myComponents)
	{
		myComponent->DestroySelf();
	}
}