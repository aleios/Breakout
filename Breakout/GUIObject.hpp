#pragma once
#ifndef GUIOBJECT_HPP
#define GUIOBJECT_HPP

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace GUI
{
	class GUIObject
	{
	public:
		GUIObject()
		{
		}

		virtual void OnEvent(const sf::Event& ev) = 0;
		virtual void OnUpdate() = 0;
		virtual void OnDraw(sf::RenderWindow& window) = 0;
	};
}

#endif