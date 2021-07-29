#pragma once
#include "Tetromino.h"

class J : public Tetromino
{
public:
	J();
	Tetromino* getCopy() override;
};
