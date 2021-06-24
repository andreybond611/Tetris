#pragma once

#include <SFML/Config.hpp>
#include <SFML/System/Vector2.hpp>
#include "GameMode.h"
#include "Tetris.h"


/**
 * One square side size in pixels
 */
constexpr sf::Uint32 squareSize = 32;

/**
 * Playfield sizes in cells
 */
static const sf::Vector2u playfieldSize { 10, 22 };
static const sf::Vector2u visiblePlayfieldSize { 10, 20 };

class Game
{
public:
	static Game& getGame()
	{
		static Game gameInstance;
		return gameInstance;
	}
	Game() = default;
	Game(const Game&) = delete;
	void operator=(const Game&) = delete;
	~Game();

	GameMode* getGameMode()const { return GameMode; }
	void startGame() { GameMode = new Tetris; }
private:
	GameMode* GameMode;
	
};

