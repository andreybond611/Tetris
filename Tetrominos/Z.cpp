#include "Z.h"

Z::Z()
{
	position[0] = sf::Vector2i(-1, -1);
	position[1] = sf::Vector2i(0, -1);
	position[2] = sf::Vector2i(0, 0);
	position[3] = sf::Vector2i(1, 0);

	symbol = 'z';

	pivotPtr = &position[2];
}

Tetromino* Z::getCopy()
{
	Tetromino* result = new Z();
	result->setPosition(getPosition());
	return result;
}

