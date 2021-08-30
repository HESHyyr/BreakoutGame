#include "Brick.h"

#include <GameManager/ObjectManager.h>
#include <Component/Render/RectangleRenderer2D.h>
#include <Component/Physics/GameCollider.h>


Brick::Brick()
{
	//Init size
	transform.w = 20;
	transform.h = 10;

	//Init components
	GameComponent* myRenderer = static_cast<GameComponent*> (ObjectManager::GetInstance().CreateObject<RectangleRenderer2D>());
	myRenderer->SetMyEntity(this);

	//To-do: Fix collider constructor and architecture
}