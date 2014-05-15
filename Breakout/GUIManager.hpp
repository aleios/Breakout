#ifndef GUIMANAGER_HPP
#define GUIMANAGER_HPP

#include <vector>
#include <memory>

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "GUIWidget.hpp"

namespace GUI
{
	class GUIManager
	{
	public:
		void OnEvent(const sf::Event& ev);
		void OnUpdate();
		void OnDraw(sf::RenderWindow& window);

		void Add(std::shared_ptr<GUIWidget> widget);
		void Remove(std::shared_ptr<GUIWidget> widget);
		void RemoveAll();
	private:
		typedef std::vector<std::shared_ptr<GUIWidget>> WidgetList;
		typedef WidgetList::iterator WidgetIter;

		WidgetList widgets;
	};
}

#endif