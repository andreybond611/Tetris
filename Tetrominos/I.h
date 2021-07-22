#pragma once
#include "Tetromino.h"

class I : public Tetromino
{
public:
	I();

	void rotate(bool isClockwise) override;

private:
	static constexpr sf::Int32 Cells = 4;
	static constexpr sf::Int32 Rotations = 4;
	
	std::array<std::array<sf::Vector2i, Cells>, Rotations> rotationOffsets;
	sf::Int32 RotationState = 0;
	void addOffset(std::array<sf::Vector2i, Cells> rotationOffset, sf::Int32 sign);
	void incrementRotationState();
	void decrementRotationState();
};

