#pragma once

#include <math.h>
#include "ComputeFStrategy.h"
/*
Best First Search is a greedy algorithm for path finding
Its base on a priority queue and hiuristic function that infrom
the algorithm who is the best node to reach the goal node
*/
class BestFirstSearchStrategy : public ComputeFStrategy
{

public:
	double ComputeF(Cell* node,Cell* target) const override 
	{
		return pow((node->getRow() - target->getRow()), 2) + pow((node->getCol() - target->getCol()), 2);
	};

};
