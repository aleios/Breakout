/* This program is free software. It comes without any warranty, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://www.wtfpl.net/ for more details. */

#pragma once
#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class State
{
public:
	virtual ~State()
	{

	}

	virtual void OnEvent(const sf::Event& ev) = 0;
	virtual void OnUpdate() = 0;
	virtual void OnDraw(sf::RenderWindow& window) = 0;
};

#endif