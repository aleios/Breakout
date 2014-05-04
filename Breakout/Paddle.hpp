/* This program is free software. It comes without any warranty, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://www.wtfpl.net/ for more details. */

#pragma once
#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

struct Paddle
{
	sf::RectangleShape shape;
	sf::Vector2f velocity;

	Paddle(float inX, float inY)
	{
		shape.setPosition(inX, inY);
		shape.setSize(sf::Vector2f(paddleWidth, paddleHeight));
		shape.setFillColor(sf::Color::Blue);
		shape.setOrigin(paddleWidth / 2, paddleHeight / 2);
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
	float left() { return x() - shape.getSize().x / 2.0f; }
	float right() { return x() + shape.getSize().x / 2.0f; }
	float top() { return y() - shape.getSize().y / 2.0f; }
	float bottom() { return y() + shape.getSize().y / 2.0f; }

	static const float paddleWidth, paddleHeight, paddleVelocity;
};
#endif