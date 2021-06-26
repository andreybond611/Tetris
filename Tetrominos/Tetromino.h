#pragma once
#include <array>
#include <SFML/Config.hpp>
#include <SFML/System/Vector2.hpp>

/**
 * \brief Base abstract class for tetrominos which are the blocks used in Tetris game
 */
class Tetromino
{
public:
	virtual ~Tetromino() = default;
	std::array<sf::Vector2i, 4> getPosition()const { return position; }
	sf::Int32 getSymbol()const { return symbol; }
	void addPosition(sf::Vector2i positionToAdd);
	virtual void rotate() = 0;
	void fall();
protected:
	std::array<sf::Vector2i, 4> position;
	sf::Int32 symbol;
};