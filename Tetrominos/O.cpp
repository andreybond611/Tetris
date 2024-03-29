#include "O.h"

O::O()
{
	position[0] = sf::Vector2i(0, -1);
	position[1] = sf::Vector2i(0, 0);
	position[2] = sf::Vector2i(1, 0);
	position[3] = sf::Vector2i(1, -1);

	symbol = 'o';

	pivotPtr = &position[1];
}

void O::rotate(bool isClockwise)
{
	// can't rotate
}

Tetromino* O::getCopy()
{
	Tetromino* result = new O();
	result->setPosition(getPosition());
	return result;
}

