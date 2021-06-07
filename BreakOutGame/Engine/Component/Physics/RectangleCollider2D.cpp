#include "RectangleCollider2D.h"

void RectangleCollider2D::CheckCollision(GameCollider* otherCollider) 
{
	if (dynamic_cast<RectangleCollider2D*>(otherCollider))
	{
		//Rectangle - Rectangle Collision

	}
}

void RectangleCollider2D::OnCollisionEnter(GameCollider* otherCollider)
{

}
