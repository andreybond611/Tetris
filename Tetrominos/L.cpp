#include "L.h"

L::L()
{
	position[0] = sf::Vector2i(-1, 0);
	position[1] = sf::Vector2i(0, 0);
	position[2] = sf::Vector2i(1, 0);
	position[3] = sf::Vector2i(1, -1);

	symbol = 'l';

	pivotPtr = &position[1];
}

Tetromino* L::getCopy()
{
	Tetromino* result = new L();
	result->setPosition(getPosition());
	return result;
}

