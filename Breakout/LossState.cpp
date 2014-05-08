#include "LossState.hpp"

LossState::LossState(Context context)
: State(context)
{
	defaultFont.loadFromFile("arial.ttf");

	lossText.setCharacterSize(80);
	lossText.setString("You Lose!");
	lossText.setPosition({ context.window.getSize().x / 2.0f, context.window.getSize().y / 2.0f });
	lossText.setColor(sf::Color::Red);
	lossText.setFont(defaultFont);
	lossText.setOrigin(lossText.getLocalBounds().width / 2, lossText.getLocalBounds().height / 2);
}

void LossState::OnEvent(const sf::Event& ev)
{

}

void LossState::OnUpdate()
{

}

void LossState::OnDraw()
{
	context.window.draw(lossText);
}