#include "T.h"

T::T()
{
	position[0] = sf::Vector2i(-1, 0);
	position[1] = sf::Vector2i(0, 0);
	position[2] = sf::Vector2i(0, -1);
	position[3] = sf::Vector2i(1, 0);

	symbol = 't';

	pivotPtr = &position[1];
}

Tetromino* T::getCopy()
{
	Tetromino* result = new T();
	result->setPosition(getPosition());
	return result;
}

