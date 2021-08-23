#pragma once

#include <unordered_set>

#include <GameManager/GameSingleton.h>
#include <Component/Physics/GameCollider.h>

using namespace std;

class PhysicsManager : public GameSingleton<PhysicsManager>
{

public:

	//Called per update
	void FindCollisions();

	unordered_set<GameCollider*> ColliderQueue;

};

