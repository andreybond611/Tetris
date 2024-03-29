#include "J.h"

J::J()
{
	position[0] = sf::Vector2i(-1, -1);
	position[1] = sf::Vector2i(-1, 0);
	position[2] = sf::Vector2i(0, 0);
	position[3] = sf::Vector2i(1, 0);

	symbol = 'j';

	pivotPtr = &position[2];
}

Tetromino* J::getCopy()
{
	Tetromino* result = new J();
	result->setPosition(getPosition());
	return result;
}

