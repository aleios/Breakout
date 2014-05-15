#ifndef GUILABEL_HPP
#define GUILABEL_HPP

#include "GUIWidget.hpp"

#include <SFML/Graphics/Text.hpp>

namespace GUI
{
	class GUILabel
		: public GUIWidget
	{
	public:
		void OnEvent(const sf::Event& ev);
		void OnUpdate();
		void OnDraw(sf::RenderWindow& window);
	private:
		sf::Text text;
	};
}

#endif