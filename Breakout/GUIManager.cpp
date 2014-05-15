#include "GUIManager.hpp"

#include <algorithm>

namespace GUI
{
	void GUIManager::OnEvent(const sf::Event& ev)
	{
		for (auto& it : widgets)
		{
			it->OnEvent(ev);
		}
	}

	void GUIManager::OnUpdate()
	{
		for (auto& it : widgets)
		{
			it->OnUpdate();
		}
	}

	void GUIManager::OnDraw(sf::RenderWindow& window)
	{
		for (auto& it : widgets)
		{
			it->OnDraw(window);
		}
	}

	void GUIManager::Add(std::shared_ptr<GUIWidget> widget)
	{
		widgets.push_back(widget);
	}

	void GUIManager::Remove(std::shared_ptr<GUIWidget> widget)
	{
		WidgetIter it = std::find(widgets.begin(), widgets.end(), widget);

		if (it != widgets.end())
			widgets.erase(it);
	}

	void GUIManager::RemoveAll()
	{
		widgets.clear();
	}
}