#include "GUIManager.hpp"

namespace GUI
{
	void GUIManager::OnEvent(const sf::Event& ev)
	{
		for (auto& it : objects)
		{
			it->OnEvent(ev);
		}
	}

	void GUIManager::OnUpdate()
	{
		for (auto& it : objects)
		{
			it->OnUpdate();
		}
	}

	void GUIManager::OnDraw(sf::RenderWindow& window)
	{
		for (auto& it : objects)
		{
			it->OnDraw(window);
		}
	}

	void GUIManager::AddObject(std::unique_ptr<GUIObject> object)
	{
		objects.push_back(std::move(object));
	}
}