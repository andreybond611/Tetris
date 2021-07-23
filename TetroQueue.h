#pragma once
#include <array>
#include <vector>
#include <SFML/Config.hpp>


class Tetromino;

constexpr sf::Int32 maxTetros = 7;

constexpr sf::Int32 queueNumber = 2;

enum class tetroType
{
	I,
	J,
	L,
	O,
	S,
	T,
	Z
};

/**
 * randomly generate sequences of tetrominos
 */
class TetroQueue
{
public:
	TetroQueue();

	/** returns next tetro and removes it from queue */
	Tetromino* getNext();
private:
	Tetromino* createTetrominoOfType(tetroType type);
	void changeQueue();
	void fillQueue(std::vector<tetroType>& queue);
	Tetromino* pop();
	
	sf::Int32 currentQueueIndex = 0;	
	std::array<std::vector<tetroType>, queueNumber> queues{ std::vector<tetroType>{},std::vector<tetroType>{} };
	std::vector<tetroType>& currentQueue = queues[currentQueueIndex];
	const std::array<tetroType, maxTetros> defaultTetros = { tetroType::I,tetroType::J,tetroType::L,tetroType::O,tetroType::S,tetroType::T,tetroType::Z };
};

