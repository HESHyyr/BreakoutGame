#pragma once


class LevelManager
{ 

public:

	void InitializeLevel(int rows, int columns);

private:

	int startPosition[2]{ 400,400 };
	int brickDistanceSetting[2]{ 50,50 };

};

