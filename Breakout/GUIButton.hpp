#pragma once
#ifndef GUIButton_HPP
#define GUIButton_HPP

#include <string>
#include <functional>

#include "GUIObject.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

namespace GUI
{
	class GUIButton
		: public GUIObject
	{
	public:
		void OnEvent(const sf::Event& ev);
		void OnUpdate();
		void OnDraw(sf::RenderWindow& window);

		void RegisterCallback(std::function<void()> func);

		// Properties
		void SetText(const std::string& text);
		const std::string& GetText() const;

		void SetFont(const sf::Font& font);
		const sf::Font& GetFont() const;

		void SetTextColor(const sf::Color& col);
		const sf::Color& GetTextColor() const;

		void SetPosition(const sf::Vector2f& pos);
		const sf::Vector2f& GetPosition() const;

		void SetSize(const sf::Vector2f& size);
		const sf::Vector2f& GetSize() const;

		void SetColor(const sf::Color& col);
		const sf::Color& GetColor() const;

		void SetTexture(const sf::Texture& tex);
		const sf::Texture& GetTexture() const;
	private:
		std::function<void()> callbackFunc;

		sf::RectangleShape buttonShape;
		sf::Text buttonText;
	};
}

#endif