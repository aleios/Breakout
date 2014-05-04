/* This program is free software. It comes without any warranty, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://www.wtfpl.net/ for more details. */

#pragma once
#ifndef BRICK_HPP
#define BRICK_HPP

#include <SFML/Graphics/RectangleShape.hpp>

struct Brick
{
	Brick(float inX, float inY);

	// Position
	float x() { return shape.getPosition().x; }
	float y() { return shape.getPosition().y; }

	// Corners
	float left() { return x() - shape.getSize().x / 2.0f; }
	float right() { return x() + shape.getSize().x / 2.0f; }
	float top() { return y() - shape.getSize().y / 2.0f; }
	float bottom() { return y() + shape.getSize().y / 2.0f; }

	sf::RectangleShape shape;
	bool destroyed;

	static const float brickWidth, brickHeight;
};

#endif