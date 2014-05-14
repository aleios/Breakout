#include "GUIButton.hpp"

namespace GUI
{
	void GUIButton::OnEvent(const sf::Event& ev)
	{
		// Need MouseX MouseY ButtonState.
		// Render information.
		if (ev.type == sf::Event::MouseButtonReleased)
		{
			if (ev.mouseButton.button == sf::Mouse::Left)
			{
				int mx = ev.mouseButton.x;
				int my = ev.mouseButton.y;

				sf::Vector2f spos = buttonShape.getPosition();
				sf::Vector2f ssize = buttonShape.getSize();

				// Test if in bounds of the button.
				if ((mx >= spos.x) && (my >= spos.y) && (mx <= (spos.x + ssize.x)) && (my <= (spos.y + ssize.y)))
					callbackFunc();
			}
		}
	}

	void GUIButton::OnUpdate()
	{

	}

	void GUIButton::OnDraw(sf::RenderWindow& window)
	{
		window.draw(buttonShape);
		window.draw(buttonText);
	}

	void GUIButton::RegisterCallback(std::function<void()> func)
	{
		callbackFunc = func;
	}

	// Properties
	void GUIButton::SetText(const std::string& text)
	{
		buttonText.setString(text);
	}

	const std::string& GUIButton::GetText() const
	{
		return buttonText.getString();
	}

	void GUIButton::SetFont(const sf::Font& font)
	{
		buttonText.setFont(font);
	}

	const sf::Font& GUIButton::GetFont() const
	{
		return *buttonText.getFont();
	}

	void GUIButton::SetTextColor(const sf::Color& col)
	{
		buttonText.setColor(col);
	}

	const sf::Color& GUIButton::GetTextColor() const
	{
		return buttonText.getColor();
	}

	void GUIButton::SetPosition(const sf::Vector2f& pos)
	{
		buttonShape.setPosition(pos);
		buttonText.setPosition(pos);
	}

	const sf::Vector2f& GUIButton::GetPosition() const
	{
		return buttonShape.getPosition();
	}

	void GUIButton::SetSize(const sf::Vector2f& size)
	{
		buttonShape.setSize(size);
	}

	const sf::Vector2f& GUIButton::GetSize() const
	{
		return buttonShape.getSize();
	}

	void GUIButton::SetColor(const sf::Color& col)
	{
		buttonShape.setFillColor(col);
	}

	const sf::Color& GUIButton::GetColor() const
	{
		return buttonShape.getFillColor();
	}

	void GUIButton::SetTexture(const sf::Texture& tex)
	{
		buttonShape.setTexture(&tex);
	}

	const sf::Texture& GUIButton::GetTexture() const
	{
		return *buttonShape.getTexture();
	}
}