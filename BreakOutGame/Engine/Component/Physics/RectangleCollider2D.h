#pragma once

#include "GameCollider.h"
#include "Utility/Math/GameMath.h"

class RectangleCollider2D :public GameCollider
{

public:

	RectangleCollider2D(GameEntity& gameEntity, unordered_set<GameCollider*> &mainColliderList, bool isStatic = true);

	virtual void CheckCollision(GameCollider* otherCollider) override;
	virtual void OnCollisionEnter(GameCollider* otherCollider) override;

private:

	BoundingBox AABB;
};

