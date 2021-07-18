#pragma once
#include <vector>
#include <SFML/Config.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

#include "GameMode.h"

#define EMPTY 0

class Tetromino;

namespace sf {
	class Shape;
}

struct PlayfieldCell
{
	sf::Int32 symbol;
	sf::Shape* image;
};

/**
 * \brief Represents the main game
 */
class Tetris : public GameMode
{
public:
	Tetris();
	~Tetris() override;
	sf::Color getColorFromSymbol(sf::Int32 symbol);
	virtual void draw(sf::RenderTarget* renderTarget) override;
	void moveFallingTetromino(sf::Vector2i direction);
	void takeCareOfInput(const sf::Event::KeyEvent& key);
	virtual void takeCareOfEvent(const sf::Event& event) override;
	virtual void update(const sf::Time& elapsedTime) override;
	std::vector<std::vector<PlayfieldCell>> getPlayfield()const { return playfield; }
private:
	void spawnTetromino(Tetromino* tetromino);
	void setCell(sf::Int32 x, sf::Int32 y, sf::Int32 symbol);
	sf::Int32 getCell(sf::Int32 x, sf::Int32 y)const;
	void drawTetromino(Tetromino* tetromino);
	void eraseTetromino(Tetromino* tetromino);
	bool isPointInPlayfieldBorders(const sf::Vector2i& point);
	bool isColliding(Tetromino* tetromino, sf::Vector2i direction);
	
	const sf::Vector2i startingPosition{4, 1};
	Tetromino* fallingTetromino;
	std::vector<std::vector<PlayfieldCell>> playfield;
	sf::Int64 timeCounter{0};
	sf::Int64 maxTime{ 1000000 };
};

