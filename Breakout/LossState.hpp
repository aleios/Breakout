/* This program is free software. It comes without any warranty, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://www.wtfpl.net/ for more details. */

#pragma once
#ifndef LOSSSTATE_HPP
#define LOSSSTATE_HPP

#include "State.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class LossState
	: public State
{
public:
	LossState(Context context);
	void OnEvent(const sf::Event& ev);
	void OnUpdate();
	void OnDraw();

private:
	sf::Font defaultFont;
	sf::Text lossText;
};

#endif