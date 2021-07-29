#include "I.h"

I::I()
{
	position[0] = sf::Vector2i(-1, 0);
	position[1] = sf::Vector2i(0, 0);
	position[2] = sf::Vector2i(1, 0);
	position[3] = sf::Vector2i(2, 0);

	symbol = 'i';

	pivotPtr = &position[1];
	
	rotationOffsets[0][0] = sf::Vector2i(2, -1);
	rotationOffsets[0][1] = sf::Vector2i(1, 0);
	rotationOffsets[0][2] = sf::Vector2i(0, 1);
	rotationOffsets[0][3] = sf::Vector2i(-1, 2);
	
	rotationOffsets[1][0] = sf::Vector2i(1, 2);
	rotationOffsets[1][1] = sf::Vector2i(0, 1);
	rotationOffsets[1][2] = sf::Vector2i(-1, 0);
	rotationOffsets[1][3] = sf::Vector2i(-2, -1);
	
	rotationOffsets[2][0] = sf::Vector2i(-2, 1);
	rotationOffsets[2][1] = sf::Vector2i(-1, 0);
	rotationOffsets[2][2] = sf::Vector2i(0, -1);
	rotationOffsets[2][3] = sf::Vector2i(1, -2);
	
	rotationOffsets[3][0] = sf::Vector2i(-1, -2);
	rotationOffsets[3][1] = sf::Vector2i(0, -1);
	rotationOffsets[3][2] = sf::Vector2i(1, 0);
	rotationOffsets[3][3] = sf::Vector2i(2, 1);
}

void I::rotate(bool isClockwise)
{
	if (isClockwise)
	{
		addOffset(rotationOffsets[RotationState], 1);
		incrementRotationState();
	}
	else
	{
		decrementRotationState();
		addOffset(rotationOffsets[RotationState], -1);	
	}
}

Tetromino* I::getCopy()
{
	Tetromino* result = new I();
	result->setPosition(getPosition());
	return result;
}

void I::addOffset(std::array<sf::Vector2i, Cells> rotationOffset, sf::Int32 sign)
{
	for (sf::Int32 pointCount = 0; pointCount < Cells; ++pointCount)
	{
		position[pointCount] += rotationOffset[pointCount] * sign;
	}
}

void I::incrementRotationState()
{
	RotationState++;
	RotationState %= Rotations;
}

void I::decrementRotationState()
{
	RotationState--;
	if (RotationState < 0)
		RotationState = Rotations - 1;
}
