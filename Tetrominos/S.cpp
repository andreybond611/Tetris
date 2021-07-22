#include "S.h"

S::S()
{
	position[0] = sf::Vector2i(-1, 0);
	position[1] = sf::Vector2i(0, 0);
	position[2] = sf::Vector2i(0, -1);
	position[3] = sf::Vector2i(1, -1);

	symbol = 's';

	pivotPtr = &position[1];
}

