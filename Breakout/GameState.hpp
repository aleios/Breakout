/* This program is free software. It comes without any warranty, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://www.wtfpl.net/ for more details. */

#pragma once
#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"

#include "Ball.hpp"
#include "Paddle.hpp"
#include "Brick.hpp"

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include <memory>

class GameState
	: public State
{
public:
	GameState(Context context);
	~GameState();

	void OnEvent(const sf::Event& ev);
	void OnUpdate();
	void OnDraw();

private:
	template<class T1, class T2>
	bool isIntersecting(T1& lhs, T2& rhs)
	{
		return lhs.right() >= rhs.left() && lhs.left() < rhs.right()
			&& lhs.bottom() >= rhs.top() && lhs.top() <= rhs.bottom();
	}

	void testCollision(Paddle& paddle, Ball& ball);
	void testCollision(Brick& brick, Ball& ball);

private:
	int windowWidth, windowHeight;

	std::unique_ptr<Ball> ball;
	std::unique_ptr<Paddle> paddle;

	std::vector<Brick> bricks;

	unsigned int lives{ 3 };

	sf::Font defaultFont;
	sf::Text msgText;

	sf::SoundBuffer bufferPaddleHit, bufferBrickHit;
	sf::Sound sndPaddleHit, sndBrickHit;
};

#endif