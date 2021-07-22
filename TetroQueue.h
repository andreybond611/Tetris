#pragma once
#include <array>
#include <vector>
#include <SFML/Config.hpp>


class Tetromino;
constexpr sf::Int32 maxTetros = 7;

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

class TetroQueue
{
public:
	TetroQueue();

	Tetromino* GetNext();
private:
	Tetromino* CreateTetrominoOfType(tetroType type);
	void changeQueue();

	void createQueue(std::vector<tetroType>& queue);
	Tetromino* pop();
	static constexpr sf::Int32 queueNumber = 2;
	sf::Int32 currentQueueIndex = 0;
	
	std::array<std::vector<tetroType>, queueNumber> queues{ std::vector<tetroType>{},std::vector<tetroType>{} };
	std::vector<tetroType>& currentQueue = queues[currentQueueIndex];
	const std::array<tetroType, maxTetros> defaultTetros = { tetroType::I,tetroType::J,tetroType::L,tetroType::O,tetroType::S,tetroType::T,tetroType::Z };
};

