/* This program is free software. It comes without any warranty, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://www.wtfpl.net/ for more details. */

#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include "Ball.hpp"
#include "Paddle.hpp"
#include "Brick.hpp"
#include "StateManager.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

template<class T1, class T2>
bool isIntersecting(T1& lhs, T2& rhs)
{
	return lhs.right() >= rhs.left() && lhs.left() < rhs.right()
		&& lhs.bottom() >= rhs.top() && lhs.top() <= rhs.bottom();
}

class Game
{
public:
	Game();
	~Game();

	void Run();

private:
	StateManager stateManager;
	sf::RenderWindow window;
	bool isQuitting{ false };
};

#endif