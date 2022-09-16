#pragma once
#include "Cell.h"
#include <functional>

class CellsComperator
{
public:
	CellsComperator();

	~CellsComperator();

	double CalculateEucludeanDistaceSqure(Cell* first, Cell* second)
	{
		return pow((first->getRow() - second->getRow()), 2) + pow((first->getCol() - second->getCol()), 2);
	}

	bool operator()(Cell* c1, Cell* c2) {
		return c1->GetF() > c2->GetF();
	}
};