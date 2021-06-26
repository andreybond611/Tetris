#include "Tetromino.h"

void Tetromino::addPosition(sf::Vector2i positionToAdd)
{
	for (auto& vector2position : position)
	{
		vector2position.x += positionToAdd.x;
		vector2position.y += positionToAdd.y;
	}
}

void Tetromino::fall()
{
	addPosition(sf::Vector2i(0, 1));
}
