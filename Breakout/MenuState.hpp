/* This program is free software. It comes without any warranty, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://www.wtfpl.net/ for more details. */

#pragma once
#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include "State.hpp"
#include "GUIManager.hpp"

#include <SFML/Graphics/Font.hpp>

#include "GUIButton.hpp"

class MenuState
	: public State
{
public:
	MenuState(Context context);

	void OnEvent(const sf::Event& ev);
	void OnUpdate();
	void OnDraw();

private:
	void OnButton();

	GUI::GUIManager gui;
	sf::Font defaultFont;
};

#endif