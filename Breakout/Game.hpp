#ifndef GAME_HPP
#define GAME_HPP

#include "Ball.hpp"
#include "Paddle.hpp"
#include "Brick.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

template<class T1, class T2>
bool isIntersecting(T1& lhs, T2& rhs)
{
	return lhs.right() >= rhs.left() && lhs.left() < rhs.right()
		&& lhs.bottom() >= rhs.top() && lhs.top() <= rhs.bottom();
}

class Game
{
public:
	Game();
	~Game();

	void Run();
private:
	void UpdateInput();

	void Update();
	void Draw();

	void testCollision(Paddle& paddle, Ball& ball);
	void testCollision(Brick& brick, Ball& ball);

	bool isQuitting{ false };
	sf::RenderWindow window;
	Ball ball{ windowWidth / 2.0f, (float)windowHeight / 2.0f };
	Paddle paddle{ windowWidth / 2.0f, windowHeight - 64.0f };

	std::vector<Brick> bricks;

	unsigned int lives{ 3 };

	sf::Font defaultFont;
	sf::Text msgText;

	sf::SoundBuffer bufferPaddleHit, bufferBrickHit;
	sf::Sound sndPaddleHit, sndBrickHit;

	const unsigned int windowWidth{ 800 }, windowHeight{ 600 };
	bool hasLost{ false };
};

#endif