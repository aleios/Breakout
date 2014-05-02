#include "Brick.hpp"
#include "GameGlobals.hpp"

const float ballVelocity{ 8.0f };

Brick::Brick(float inX, float inY)
	: destroyed(false)
{
	shape.setPosition(inX, inY);
	shape.setFillColor(sf::Color::Green);
	shape.setSize(sf::Vector2f(brickWidth, brickHeight));
	shape.setOrigin(brickWidth / 2, brickHeight / 2);
}