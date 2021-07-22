#include "Tetromino.h"

void Tetromino::addPosition(sf::Vector2i positionToAdd)
{
	for (auto& vector2position : position)
	{
		vector2position.x += positionToAdd.x;
		vector2position.y += positionToAdd.y;
	}
}

void Tetromino::rotate(bool isClockwise)
{
	for (auto& point : position)
	{
		if (point != *pivotPtr)
		{
			sf::Vector2i result = point - *pivotPtr;                           // translating to origin [0;0]
			
			result = isClockwise ? sf::Vector2i{ -result.y, result.x }     // rotating
									: sf::Vector2i{ result.y, -result.x };			
			result = result + *pivotPtr;                                       // translating back
			point = result;
		}
	}
}

void Tetromino::fall()
{
	addPosition(sf::Vector2i(0, 1));
}
