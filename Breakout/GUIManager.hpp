#ifndef GUIMANAGER_HPP
#define GUIMANAGER_HPP

#include <vector>
#include <memory>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "GUIObject.hpp"

namespace GUI
{
	class GUIManager
	{
	public:
		void OnEvent(const sf::Event& ev);
		void OnUpdate();
		void OnDraw(sf::RenderWindow& window);

		void AddObject(std::unique_ptr<GUIObject> object);
	private:
		std::vector<std::unique_ptr<GUIObject>> objects;
	};
}

#endif