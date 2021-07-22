#pragma once
#include "Tetromino.h"

class O : public Tetromino
{
public:
	O();
	void rotate(bool isClockwise) override;
};
