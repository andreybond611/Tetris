#pragma once

#include <SFML/Config.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/VideoMode.hpp>
#include "GameMode.h"


/**
 * One square side size in pixels
 */
constexpr sf::Uint32 squareSize = 32;

/**
 * Playfield sizes in cells
 */
static const sf::Vector2u playfieldSize { 10, 20 };
static const sf::Vector2u visiblePlayfieldSize { 10, 20 };

class Game
{
public:
	Game() = default;
	Game(const Game&) = delete;
	void operator=(const Game&) = delete;
	~Game();

	void run();
private:
	void startGame();
	void render();
	void update();
	void processEvents();
	
	GameMode* gameMode{};
	sf::Clock clock;
	sf::VideoMode videoMode{ visiblePlayfieldSize.x * squareSize, visiblePlayfieldSize.y * squareSize };
	sf::RenderWindow window{ videoMode, "Tetris" };
};

