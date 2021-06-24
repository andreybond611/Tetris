#include "Game.h"


Game::~Game()
{
	delete GameMode;
	GameMode = nullptr;
}
