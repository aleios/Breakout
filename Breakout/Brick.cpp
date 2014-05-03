#include "Brick.hpp"

const float Brick::brickWidth{ 30 }, Brick::brickHeight{ 20 };

Brick::Brick(float inX, float inY)
	: destroyed(false)
{
	shape.setPosition(inX, inY);
	shape.setFillColor(sf::Color::Green);
	shape.setSize(sf::Vector2f(brickWidth, brickHeight));
	shape.setOrigin(brickWidth / 2, brickHeight / 2);
}