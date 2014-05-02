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
};

#endif