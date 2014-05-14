#include "GameState.hpp"
#include "GameSettings.hpp"

#include "StateManager.hpp"
#include "LossState.hpp"

GameState::GameState(Context context)
	: State(context)
{
	GameSettings* settings = GameSettings::GetInstance();

	windowWidth = settings->GetSettingInt("WindowWidth");
	windowHeight = settings->GetSettingInt("WindowHeight");

	ball = std::make_unique<Ball>(windowWidth / 2.0f, windowHeight / 2.0f);
	paddle = std::make_unique<Paddle>(windowWidth / 2.0f, windowHeight - 64.0f);
	//{ windowWidth / 2.0f, windowHeight - 64.0f }

	const int brickRows = 5;
	const int brickCols = 22;
	// Create our bricks.
	for (auto y = 0; y < brickRows; y++)
		for (auto x = 0; x < brickCols; x++)
			bricks.emplace_back((x + 1) * (Brick::brickWidth + 3) + 22, (y + 2) * (Brick::brickHeight + 3));

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

GameState::~GameState()
{
}

void GameState::OnEvent(const sf::Event& ev)
{

}

void GameState::OnUpdate()
{
	// Move players paddle.
	sf::Vector2f paddlePos = paddle->GetPosition();
	sf::Vector2i mousePos = sf::Mouse::getPosition(context.window);
	if (mousePos.x > windowWidth)
		mousePos.x = windowWidth;
	if (mousePos.x < 0)
		mousePos.x = 0;
	paddlePos.x = mousePos.x;
	paddle->SetPosition(paddlePos);

	// Initial Check
	if (!ballCanMove && sf::Mouse::isButtonPressed(sf::Mouse::Left))
		ballCanMove = true;

	// Update
	if (ball->left() < 0)
	{
		ball->velocity.x = Ball::ballVelocity;
	}
	else if (ball->right() > windowWidth)
	{
		ball->velocity.x = -Ball::ballVelocity;
	}

	if (ball->top() < 0)
	{
		ball->velocity.y = Ball::ballVelocity;
	}
	else if (ball->bottom() > windowHeight)
	{
		ball->velocity.y = -Ball::ballVelocity;
	}

	if (ballCanMove)
		ball->Update();

	paddle->Update();

	testCollision(*paddle, *ball);

	// Test if the ball has gone below the paddle (fail condition)
	if (ball->y() >= (windowHeight - ball->radius))
	{
		paddle->SetPosition({ windowWidth / 2.0f, windowHeight - 64.0f });
		ball->SetPosition({ windowWidth / 2.0f, windowHeight / 2.0f });
		lives--;
		ballCanMove = false;
	}

	// Test ball-brick collisions
	for (auto& brick : bricks)
		testCollision(brick, *ball);

	// Remove dead bricks.
	bricks.erase(std::remove_if(std::begin(bricks), std::end(bricks), [](const Brick& brick){ return brick.destroyed; }), std::end(bricks));

	// Loss
	if (lives <= 0)
		context.stateManager.PushState(std::move(std::make_unique<LossState>(context)));
}

void GameState::OnDraw()
{
	sf::RenderWindow& window = context.window;

	window.draw(ball->shape);
	window.draw(paddle->shape);

	for (auto& brick : bricks)
		window.draw(brick.shape);
}

void GameState::testCollision(Paddle& paddle, Ball& ball)
{
	if (!isIntersecting(paddle, ball)) return;

	ball.velocity.y = -Ball::ballVelocity;

	if (sndPaddleHit.getStatus() != sf::Sound::Playing)
		sndPaddleHit.play();

	if (ball.x() < paddle.x())
		ball.velocity.x = -Ball::ballVelocity;
	else
		ball.velocity.x = Ball::ballVelocity;
}

void GameState::testCollision(Brick& brick, Ball& ball)
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
		ball.velocity.x = ballFromLeft ? -Ball::ballVelocity : Ball::ballVelocity;
	else
		ball.velocity.y = ballFromTop ? -Ball::ballVelocity : Ball::ballVelocity;

	// Play a sound when the ball hits a brick.
	if (sndBrickHit.getStatus() != sf::Sound::Playing)
		sndBrickHit.play();
}