#pragma once
#include "Tetromino.h"

class T : public Tetromino
{
public:
	T();
	Tetromino* getCopy() override;
};
