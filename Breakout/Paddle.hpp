#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <SFML/Graphics.hpp>

const float paddleWidth{ 80.0f }, paddleHeight{ 15.0f }, paddleVelocity{ 11.0f };

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
};

#endif