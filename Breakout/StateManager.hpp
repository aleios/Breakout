/* This program is free software. It comes without any warranty, to
* the extent permitted by applicable law. You can redistribute it
* and/or modify it under the terms of the Do What The Fuck You Want
* To Public License, Version 2, as published by Sam Hocevar. See
* http://www.wtfpl.net/ for more details. */

#pragma once
#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP

#include <vector>
#include <memory>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class State;

class StateManager
{
public:
	StateManager();
	~StateManager();

	void PushState(std::unique_ptr<State> inState);
	void PopState();

	void OnEvent(const sf::Event& ev);
	void OnUpdate();
	void OnDraw(sf::RenderWindow& window);
private:
	std::vector<std::unique_ptr<State>> states;
};

#endif