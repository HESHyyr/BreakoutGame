#pragma once

#include <Core/CoreClass.h>

class LevelManager : public GameEntity
{ 

public:

	LevelManager();

	void Init() override;
	void InitializeLevel(int rows, int columns);

private:

	int startPosition[2];
	int brickDistanceSetting[2];

};

