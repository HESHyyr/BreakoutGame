#pragma once
struct Vector2 {

	float x, y;

	Vector2() { this->x = 0; this->y = 0; };
	Vector2(float x, float y) { this->x = x; this->y = y; };


#pragma region Math Funtions

	float Length() const;
	Vector2 UnitVector() const;
	float Dot(Vector2 otherVector) const;


#pragma endregion


#pragma region Operator Override

	Vector2 operator+(const Vector2& other) const;
	Vector2 operator-(const Vector2& other) const;
	Vector2 operator-() const;

#pragma endregion



};

typedef struct LineEquation
{

	float a, b, c;

	//Make a 2D line based on two point
	LineEquation(Vector2 p1, Vector2 p2) { a = p2.y - p1.y; b = p1.x - p2.x; c = p1.y * p2.x - p1.x * p2.y; };

	//Distance to a dot
	float DistanceToDot(Vector2 dot) const;

} LineEquation;

