#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <SFML/Graphics/RenderWindow.hpp>

class StateManager;

struct Context
{
	StateManager& stateManager;
	sf::RenderWindow& window;
};

#endif