#include "GameCollider.h"

GameCollider::GameCollider(GameComponent& gameEntity, unordered_set<GameCollider*> &mainColliderList, ColliderType type, bool isStatic, bool isPhysical)
	:GameComponent::GameComponent(gameEntity), colliderList(mainColliderList), myType(type), isStatic(isStatic), isPhysical(isPhysical)
{
	colliderList.insert(this);
}

void GameCollider::CheckCollision(GameCollider* otherCollider)
{
	bool isCollided = false;
	if(myType == ColliderType::Rectangle && otherCollider->myType == ColliderType::Rectangle)
	{
		//Collision between Rectangles
		if(CheckRectangleCollision(Vector2(myGameEntity.transform.x, myGameEntity.transform.y), 
			Vector2(myGameEntity.transform.x + myGameEntity.transform.h, myGameEntity.transform.y + myGameEntity.transform.w),
			Vector2(otherCollider->myGameEntity.transform.x, otherCollider->myGameEntity.transform.y),
			Vector2(otherCollider->myGameEntity.transform.x + otherCollider->myGameEntity.transform.h, 
				otherCollider->myGameEntity.transform.y + otherCollider->myGameEntity.transform.w)))
		{
			OnCollisionEnter(otherCollider);
		}
	}
	else if(myType == ColliderType::Circle && otherCollider->myType == ColliderType::Circle)
	{
		//Collision between Circles
		if(CheckCircleCollision(Vector2(myGameEntity.transform.x, myGameEntity.transform.y), myGameEntity.transform.h,
			Vector2(otherCollider->myGameEntity.transform.x, otherCollider->myGameEntity.transform.y), 
			otherCollider->myGameEntity.transform.h))
		{
			OnCollisionEnter(otherCollider);
		}
	}
	else 
	{
		//Collision between Rectangles and Circles
		if(myType == ColliderType::Circle)
		{
			if(CheckRectCircleCollision(Vector2(otherCollider->myGameEntity.transform.x, otherCollider->myGameEntity.transform.y),
				Vector2(otherCollider->myGameEntity.transform.w, otherCollider->myGameEntity.transform.h),
				Vector2(myGameEntity.transform.x, myGameEntity.transform.y),
				myGameEntity.transform.w))
			{
				OnCollisionEnter(otherCollider);
			}
		}
		else
		{
			if (CheckRectCircleCollision(Vector2(myGameEntity.transform.x, myGameEntity.transform.y),
				Vector2(myGameEntity.transform.w, myGameEntity.transform.h),
				Vector2(otherCollider->myGameEntity.transform.x, otherCollider->myGameEntity.transform.y),
				otherCollider->myGameEntity.transform.w))
			{
				OnCollisionEnter(otherCollider);
			}
		}
	}
}

void GameCollider::OnCollisionEnter(GameCollider* otherCollider)
{

}

void GameCollider::DestroySelf() 
{
	colliderList.erase(this);
}

bool GameCollider::CheckRectangleCollision(const Vector2 &minA, const Vector2 &maxA, const Vector2 &minB, const Vector2 &maxB)
{
	if (minA.x > maxB.x || minA.y > maxB.y || maxA.x < minB.x || maxA.y < minB.y)
		return false;
	else
		return true;
}

bool GameCollider::CheckCircleCollision(const Vector2 &centerA, const int &radiusA, const Vector2 &centerB, const int &radiusB)
{
	double distanceX = centerA.x - centerB.x;
	double distanceY = centerA.y - centerB.y;
	double centerDistance = radiusA + radiusB;

	if ((distanceX * distanceX + distanceY * distanceY) > centerDistance * centerDistance)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool GameCollider::CheckRectCircleCollision(const Vector2 &rectPosition, const Vector2 &rectScale, const Vector2 &circleCenter, const int &raduis)
{
	//check if circle center is already inside the rectangle

	Vector2 bottomRightPoint(rectPosition.x + rectScale.x, rectPosition.y + rectScale.y);

	if(circleCenter.x >= rectPosition.x && circleCenter.y >= rectPosition.y && circleCenter.x <= bottomRightPoint.x && circleCenter.y <= bottomRightPoint.y)
	{
		return true;
	}

	Vector2 topRightPoint(rectPosition.x + rectScale.x, rectPosition.y);
	Vector2 bottomLeftPoint(rectPosition.x, rectPosition.y + rectScale.y);

	LineEquation lineLeft(rectPosition, bottomLeftPoint);
	LineEquation lineTop(rectPosition, topRightPoint);
	LineEquation lineRight(topRightPoint, bottomRightPoint);
	LineEquation lineBottom(bottomLeftPoint, bottomRightPoint);

	if(lineLeft.DistanceToDot(circleCenter) <= raduis || lineTop.DistanceToDot(circleCenter) <= raduis || lineRight.DistanceToDot(circleCenter) <= raduis
		|| lineBottom.DistanceToDot(circleCenter) <= raduis)
	{
		return true;
	}

	return false;
}