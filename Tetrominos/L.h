#pragma once
#include "Tetromino.h"

class L : public Tetromino
{
public:
	L();
	Tetromino* getCopy() override;
};
