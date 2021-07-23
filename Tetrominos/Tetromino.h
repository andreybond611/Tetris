#pragma once
#include <array>
#include <SFML/Config.hpp>
#include <SFML/System/Vector2.hpp>

constexpr sf::Int32 cellNumber = 4;

/**
 * \brief Base abstract class for tetrominos which are the blocks used in Tetris game
 */
class Tetromino
{
public:
	virtual ~Tetromino() = default;

	/** change position */
	void addPosition(sf::Vector2i positionToAdd);

	/** manipulate position to rotate around pivot */
	virtual void rotate(bool isClockwise);
	
	/** drop 1 cell down  */
	void fall();

	/** getters */

	[[nodiscard]] std::array<sf::Vector2i, cellNumber> getPosition()const { return position; }

	[[nodiscard]] sf::Int32 getSymbol()const { return symbol; }

protected:
	/** points of each cell on the playfield */
	std::array<sf::Vector2i, cellNumber> position;

	/** value which represents tetromino in playfield matrix */
	sf::Int32 symbol;

	/** points at element in position array with (0;0)  */
	sf::Vector2i* pivotPtr {};
};