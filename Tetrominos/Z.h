#pragma once
#include "Tetromino.h"

class Z : public Tetromino
{
public:
	Z();
	Tetromino* getCopy() override;
};
