#pragma once

#include <unordered_set>

#include <GameManager/GameSingleton.h>
#include <Component/Render/GameRenderer.h>

using namespace std;

class RenderManager : public GameSingleton<RenderManager>
{

public:


	unordered_set<GameRenderer*> RenderQueue;
};

