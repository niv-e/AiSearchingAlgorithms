#pragma once

#include <math.h>
#include "ComputeFStrategy.h"

class AStarStrategy : public ComputeFStrategy
{

private:
	double _huristicFunction(Cell* first, Cell* second)
	{
		return pow((first->getRow() - second->getRow()), 2) + pow((first->getCol() - second->getCol()), 2);
	}

public:
	double ComputeF(Cell* node, Cell* target) const override
	{
		return node->GetG() + pow((node->getRow() - target->getRow()), 2) + pow((node->getCol() - target->getCol()), 2);
	};

};
