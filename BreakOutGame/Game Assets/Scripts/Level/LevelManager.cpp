#include "LevelManager.h"
#include <stdlib.h>

#include <GameManager/ObjectManager.h>
#include <Utility/DataStructures/Color.h>

#include <Sprites/Brick.h>

void LevelManager::InitializeLevel(int rows, int columns)
{
	for (int row = 0; row < rows; row++)
	{
		Color brickColor = Color::commonColors[rand() % CommonColors::ColorCount];
		for(int column = 0; column < columns; column++)
		{
			Brick* brick = static_cast<Brick*>(ObjectManager::GetInstance().CreateObject<Brick>());

			//Init Brick Setting
			brick->ChangePosition(startPosition[0] + column * brickDistanceSetting[1], startPosition[1] + row * brickDistanceSetting[0]);

		}
	}
}
