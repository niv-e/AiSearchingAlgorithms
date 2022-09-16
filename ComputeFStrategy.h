#pragma once
#include "Cell.h"

class ComputeFStrategy
{
public:
	ComputeFStrategy() = default;
	virtual double ComputeF(Cell* c1, Cell* c2) const = 0;
};