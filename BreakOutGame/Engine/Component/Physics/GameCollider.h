#pragma once

#include <unordered_set>

#include <Core/CoreClass.h>
#include <Utility/Math/GameMath.h>

struct BoundingBox
{
	Vector2 min;
	Vector2 max;
};

class GameCollider :public GameComponent
{
public:

	enum ColliderType
	{
		Circle,
		Rectangle
	};

	bool isStatic = true;
	bool isPhysical = true;


	GameCollider(GameComponent& gameEntity, unordered_set<GameCollider*> &mainColliderList, ColliderType type, bool isStatic = true, bool isPhysical = true);
	virtual void DestroySelf() override;

protected:

	virtual void CheckCollision(GameCollider* otherCollider);
	virtual void OnCollisionEnter(GameCollider* otherCollider);
	//virtual void OnCollisionStay(GameCollider* otherCollider);
	//virtual void OnCollisionExit(GameCollider* otherCollider);

	ColliderType myType;

private:

	BoundingBox myBoundingBox;

	unordered_set<GameCollider*> &colliderList;

	bool CheckRectangleCollision(const Vector2 &minA, const Vector2 &maxA, const Vector2 &minB, const Vector2 &maxB);
	bool CheckCircleCollision(const Vector2 &centerA, const int &radiusA, const Vector2 &centerB, const int &radiusB);
	bool CheckRectCircleCollision(const Vector2 &rectPosition, const Vector2 &rectScale, const Vector2 &circleCenter, const int &raduis);
};

