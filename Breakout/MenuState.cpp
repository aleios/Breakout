#include "MenuState.hpp"

#include "GUIButton.hpp"

#include "GameState.hpp"
#include "StateManager.hpp"

MenuState::MenuState(Context context)
	: State(context)
{
	defaultFont.loadFromFile("arial.ttf");

	auto playButton = std::make_unique<GUI::GUIButton>();
	playButton->SetSize(sf::Vector2f(150, 50));
	playButton->SetPosition(sf::Vector2f(100, 100));
	playButton->SetText("Play Game");
	playButton->SetFont(defaultFont);
	playButton->SetColor(sf::Color::Red);

	playButton->RegisterCallback(std::bind(&MenuState::OnButton, this));

	gui.AddObject(std::move(playButton));
}

void MenuState::OnEvent(const sf::Event& ev)
{
	gui.OnEvent(ev);
}

void MenuState::OnUpdate()
{
	gui.OnUpdate();
}

void MenuState::OnDraw()
{
	gui.OnDraw(context.window);
}

void MenuState::OnButton()
{
	context.stateManager.PushState(std::move(std::make_unique<GameState>(context)));
}