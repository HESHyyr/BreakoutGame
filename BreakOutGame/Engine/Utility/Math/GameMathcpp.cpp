#include <cmath>
#include "GameMath.h"

double LineEquation::DistanceToDot(Vector2 dot)
{
	return abs(a * dot.x + b * dot.y + c) / sqrt(a * a + b * b);
}