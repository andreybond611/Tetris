#pragma once
#include "Tetromino.h"

class S : public Tetromino
{
public:
	S();
	Tetromino* getCopy() override;
};
