#include "PlayerPaddle.h"

#include <GameManager/ObjectManager.h>
#include <Component/Render/RectangleRenderer2D.h>
#include <Component/Physics/GameCollider.h>

PlayerPaddle::PlayerPaddle()
{
	//Init size
	transform.w = 100;
	transform.h = 10;

	//Init components
	GameComponent* myRenderer = static_cast<GameComponent*> (ObjectManager::GetInstance().CreateObject<RectangleRenderer2D>());
	myRenderer->SetMyEntity(this);
}
