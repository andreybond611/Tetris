#include "TetroQueue.h"
#include "TetrominoHeaders.h"
#include <algorithm>
#include <random>

TetroQueue::TetroQueue()
{
	queues[0] = std::vector(defaultTetros.begin(), defaultTetros.end());

	std::random_device rd;
	std::mt19937 generator(rd());
	std::ranges::shuffle(queues[0], generator);

	queues[1] = queues[0];
	std::ranges::shuffle(queues[1], generator);
}

Tetromino* TetroQueue::pop()
{
	const tetroType type = currentQueue[currentQueue.size() - 1];
	currentQueue.pop_back();

	return createTetrominoOfType(type);
}

void TetroQueue::changeQueue()
{
	currentQueueIndex++;
	currentQueueIndex %= queueNumber;

	fillQueue(currentQueue);

	currentQueue = queues[currentQueueIndex];
}

Tetromino* TetroQueue::getNext()
{
	if (!currentQueue.empty())
	{
		return pop();
	}
	changeQueue();
	return pop();

}

void TetroQueue::fillQueue(std::vector<tetroType>& queue)
{
	queue = std::vector(defaultTetros.begin(), defaultTetros.end());

	std::random_device rd;
	std::mt19937 generator(rd());
	std::ranges::shuffle(queue, generator);
}

Tetromino* TetroQueue::createTetrominoOfType(tetroType type)
{
	switch (type)
	{
	case tetroType::I:
		return new I();
	case tetroType::J:
		return new J();
	case tetroType::L:
		return new L();
	case tetroType::O:
		return new O();
	case tetroType::S:
		return new S();
	case tetroType::T:
		return new T();
	case tetroType::Z:
		return new Z();
	default:
		return nullptr;
	}
}
