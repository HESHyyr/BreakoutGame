#include <cmath>
#include "GameMath.h"

Vector2 Vector2::operator+(const Vector2& other) const
{
	return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
	return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator-() const
{
	return Vector2(-x, -y);
}

float Vector2::Length() const
{
	return sqrt(x * x + y * y);
}

Vector2 Vector2::UnitVector() const
{
	float vectorLength = this->Length();
	return Vector2(x / vectorLength, y / vectorLength);
}

float Vector2::Dot(Vector2 otherVector) const
{
	return x * otherVector.x + y * otherVector.y;
}


float LineEquation::DistanceToDot(Vector2 dot) const
{
	return abs(a * dot.x + b * dot.y + c) / sqrt(a * a + b * b);
}