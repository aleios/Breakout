#include <iostream>
#include <vector>

#include "GameGlobals.hpp"
#include "Game.hpp"

const unsigned int brickRows{ 5 }, brickCols{ 22 };
const float brickWidth{ 30 }, brickHeight{ 20 };

int main(int argc, char** argv)
{
	Game game;
	game.Run();

	return 0;
}