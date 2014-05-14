#include "Game.hpp"
#include "GameSettings.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"

Game::Game()
{
	GameSettings* config = GameSettings::GetInstance();
	config->LoadConfig("settings.txt");
	
	int windowWidth = config->GetSettingInt("WindowWidth");
	int windowHeight = config->GetSettingInt("WindowHeight");

	// Create and setup the rendering window.
	window.create(sf::VideoMode(windowWidth, windowHeight, 32), "Breakout");
	window.setFramerateLimit(60);
}

Game::~Game()
{

}

void Game::Run()
{
	// Push game state onto the stack.
	stateManager.PushState(std::make_unique<MenuState>(Context{ stateManager, window }));

	while (!isQuitting)
	{
		// Pass along and process window input.
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			stateManager.OnEvent(ev);

			switch (ev.type)
			{
			case sf::Event::Closed:
				isQuitting = true;
				break;

			case sf::Event::KeyReleased:
				if (ev.key.code == sf::Keyboard::Escape)
					isQuitting = true;
				break;
			}
		}

		// Updates states.
		stateManager.OnUpdate();
		
		// Draw states.
		window.clear();
		stateManager.OnDraw();
		window.display();
	}
}