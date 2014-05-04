#include "StateManager.hpp"
#include "State.hpp"

StateManager::StateManager()
{
}

StateManager::~StateManager()
{

}

void StateManager::PushState(std::unique_ptr<State> inState)
{
	states.push_back(std::move(inState));
}

void StateManager::PopState()
{
	if (states.size() > 0)
		states.pop_back();
}

void StateManager::OnEvent(const sf::Event& ev)
{
	if (states.size() > 0)
		states.back()->OnEvent(ev);
}

void StateManager::OnUpdate()
{
	if (states.size() > 0)
		states.back()->OnUpdate();
}

void StateManager::OnDraw(sf::RenderWindow& window)
{
	if (states.size() > 0)
		states.back()->OnDraw(window);
}