#pragma once
typedef struct Vector2 {
	double x, y;

	Vector2(double x, double y) { this->x = x; this->y = y; };

} Vector2;

typedef struct LineEquation
{

	double a, b, c;

	//Make a 2D line based on two point
	LineEquation(Vector2 p1, Vector2 p2) { a = p2.y - p1.y; b = p1.x - p2.x; c = p1.y * p2.x - p1.x * p2.y; };

	//Distance to a dot
	double DistanceToDot(Vector2 dot);

} LineEquation;

