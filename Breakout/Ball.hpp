/* This program is free software. It comes without any warranty, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://www.wtfpl.net/ for more details. */

#ifndef BALL_HPP
#define BALL_HPP

#include <SFML/Graphics.hpp>

struct Ball
{
	sf::CircleShape shape;
	float radius;

	sf::Vector2f velocity;

	Ball(float inX, float inY, float inRadius = 10.0f)
		: velocity(-ballVelocity, -ballVelocity)
	{
		radius = inRadius;

		shape.setPosition(inX, inY);
		shape.setRadius(inRadius);
		shape.setFillColor(sf::Color::Red);
		shape.setOrigin(inRadius, inRadius);
	}

	void Update()
	{
		shape.move(velocity);
	}

	// Position
	void SetPosition(sf::Vector2f pos)
	{
		shape.setPosition(pos);
	}

	float x() { return shape.getPosition().x; }
	float y() { return shape.getPosition().y; }

	// Corners
	float left() { return x() - radius; }
	float right() { return x() + radius; }
	float top() { return y() - radius; }
	float bottom() { return y() + radius; }

	static const float ballVelocity;
};

#endif