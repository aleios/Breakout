#include "Game.hpp"
#include "GameGlobals.hpp"

Game::Game()
{
	// Create and setup the rendering window.
	window.create({ windowWidth, windowHeight, 32 }, "Breakout");
	window.setFramerateLimit(60);

	// Create our bricks.
	for(auto y = 0; y < brickRows; y++)
		for(auto x = 0; x < brickCols; x++)
			bricks.emplace_back((x + 1) * (brickWidth + 3) + 22, (y + 2) * (brickHeight + 3));

	// Load the font.
	defaultFont.loadFromFile("arial.ttf");

	// Setup the loss message
	msgText.setCharacterSize(80);
	msgText.setString("You Lose!");
	msgText.setPosition({ windowWidth / 2.0f, windowHeight / 2.0f });
	msgText.setColor(sf::Color::Red);
	msgText.setFont(defaultFont);
	msgText.setOrigin(msgText.getLocalBounds().width / 2, msgText.getLocalBounds().height / 2);

	// Setup the sounds
	bufferBrickHit.loadFromFile("brickhit.ogg");
	bufferPaddleHit.loadFromFile("paddlehit.ogg");

	sndBrickHit.setBuffer(bufferBrickHit);
	sndPaddleHit.setBuffer(bufferPaddleHit);
}

Game::~Game()
{

}

void Game::Run()
{
	while (!isQuitting)
	{
		UpdateInput();
		Update();
		Draw();
	}
}

void Game::UpdateInput()
{
	sf::Event ev;
	while (window.pollEvent(ev))
	{
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

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && paddle.left() > 0)
	{
		paddle.velocity.x = -paddleVelocity;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && paddle.right() < windowWidth)
	{
		paddle.velocity.x = paddleVelocity;
	}
	else
		paddle.velocity.x = 0;
}

void Game::Update()
{
	if (hasLost)
		return;

	// Update
	if (ball.left() < 0)
	{
		ball.velocity.x = ballVelocity;
	}
	else if (ball.right() > windowWidth)
	{
		ball.velocity.x = -ballVelocity;
	}

	if (ball.top() < 0)
	{
		ball.velocity.y = ballVelocity;
	}
	else if (ball.bottom() > windowHeight)
	{
		ball.velocity.y = -ballVelocity;
	}

	ball.Update();
	paddle.Update();

	testCollision(paddle, ball);

	// Test if the ball has gone below the paddle (fail condition)
	if (ball.y() >= (windowHeight - ball.radius))
	{
		paddle.SetPosition({ windowWidth / 2.0f, windowHeight - 64.0f });
		ball.SetPosition({ windowWidth / 2.0f, windowHeight / 2.0f });
		lives--;
	}

	if (lives < 1)
		hasLost = true;

	// Test ball-brick collisions
	for (auto& brick : bricks)
		testCollision(brick, ball);

	// Remove dead bricks.
	bricks.erase(std::remove_if(std::begin(bricks), std::end(bricks), [](const Brick& brick){ return brick.destroyed; }), std::end(bricks));
}

void Game::Draw()
{
	if (hasLost)
	{
		window.clear();

		window.draw(msgText);

		window.display();
	}
	else
	{
		// Draw
		window.clear();
		window.draw(ball.shape);
		window.draw(paddle.shape);

		for (auto& brick : bricks)
			window.draw(brick.shape);

		window.display();
	}
}

void Game::testCollision(Paddle& paddle, Ball& ball)
{
	if (!isIntersecting(paddle, ball)) return;

	ball.velocity.y = -ballVelocity;

	if (sndPaddleHit.getStatus() != sf::Sound::Playing)
		sndPaddleHit.play();

	if (ball.x() < paddle.x())
		ball.velocity.x = -ballVelocity;
	else
		ball.velocity.x = ballVelocity;
}

void Game::testCollision(Brick& brick, Ball& ball)
{
	if (!isIntersecting(brick, ball)) return;

	brick.destroyed = true;

	float overlapLeft(ball.right() - brick.left());
	float overlapRight(brick.right() - ball.left());
	float overlapTop(ball.bottom() - brick.top());
	float overlapBottom(brick.bottom() - ball.top());

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX(ballFromLeft ? overlapLeft : overlapRight);
	float minOverlapY(ballFromTop ? overlapTop : overlapBottom);

	if (abs(minOverlapX) < abs(minOverlapY))
		ball.velocity.x = ballFromLeft ? -ballVelocity : ballVelocity;
	else
		ball.velocity.y = ballFromTop ? -ballVelocity : ballVelocity;

	// Play a sound when the ball hits a brick.
	if (sndBrickHit.getStatus() != sf::Sound::Playing)
		sndBrickHit.play();
}