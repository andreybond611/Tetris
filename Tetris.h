#pragma once
#include <vector>
#include <SFML/Config.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

#include "GameMode.h"
#include "TetroQueue.h"

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
 * \brief The main game
 */
class Tetris : public GameMode
{
public:
	Tetris();
	~Tetris() override;
	virtual void draw(sf::RenderTarget* renderTarget) override;
	virtual void processEvent(const sf::Event& event) override;
	virtual void update(const sf::Time& elapsedTime) override;
	
private:
	/** change position and rotation of falling tetromino */
	
	void moveFallingTetromino(sf::Vector2i direction);
	void rotateFallingTetromino(bool isClockwise);

	/** handle key presses */
	void processInput(const sf::Event::KeyEvent& key);
	
	sf::Color getColorFromSymbol(sf::Int32 symbol);

	/** create controlled tetromino at starting position */
	void spawnTetromino(Tetromino* tetromino);

	/** work with playfield cells */
	
	void setCell(sf::Int32 x, sf::Int32 y, sf::Int32 symbol);
	[[nodiscard]]sf::Int32 getCell(sf::Int32 x, sf::Int32 y)const;

	/** puts symbols from tetromino's position in playfield matrix */
	void drawTetromino(Tetromino* tetromino);
	
	/** puts EMPTY instead of tetromino's symbols in playfield matrix */
	void eraseTetromino(Tetromino* tetromino);

	/** true if 0 > point < playfieldSize */
	bool isPointInPlayfieldBorders(const sf::Vector2i& point);

	/** true if collides on moving */	
	bool isColliding(Tetromino* tetromino, sf::Vector2i direction);

	/** true if collides on rotation */
	bool isColliding(Tetromino* tetromino, bool isClockwise);

	/** change speed of falling tetrominos */
	
	void speedUp();
	void slowDown();

	/** clear lines */
	 
	void clearFilledLines();
	void removeRowAtIndex(sf::Int32 index);
	void dropDownAllRowsBefore(sf::Int32 rowIndex);

	/** called when falling tetromino cannot move anymore*/
	void nextTetromino();

	/** tetrominos spawn in this position on playfield */
	const sf::Vector2i startingPosition{4, 1};

	/** tetromino controlled by input */
	Tetromino* fallingTetromino;

	TetroQueue tetroQueue{};

	/** two dimensional array of cells*/
	std::vector<std::vector<PlayfieldCell>> playfield;

	/** time variables */
	
	sf::Int64 timeCounter{0};
	sf::Int64 maxTime{ 500000 };
	sf::Int64 fastSpeedTime {50000};
	sf::Int64 normalSpeedTime {500000};
};

