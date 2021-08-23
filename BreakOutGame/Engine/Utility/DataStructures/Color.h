#pragma once

#include <cstdint>

enum CommonColors
{
	black = 0,
	white,
	blue,
	cyan,
	gray,
	green,
	magenta,
	red,
	yellow,
	clear,
	ColorCount
};

struct Color
{

	Color() {};

	Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 0)
		: r(red), g(green), b(blue), a(alpha)
	{};
	


	uint8_t r, g, b, a;

	//Constant Common colors
	static const Color commonColors[CommonColors::ColorCount];
	
};