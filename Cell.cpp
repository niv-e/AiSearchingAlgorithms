#include "Cell.h"


Cell::Cell()
{
}

Cell::Cell(int r, int c)
{
	row = r;
	col = c;
	SourceParent = nullptr; // has no parent
	TargetParent = nullptr; // has no parent
}

Cell::Cell(int r, int c,Cell* p)
{
	row = r;
	col = c;
	setParent(p);
}

Cell::Cell(int r, int c, int color)
{
	row = r;
	col = c;
	Color = color;
}

Cell::Cell(int r, int c, int color, Cell * p)
{
	row = r;
	col = c;
	Color = color;
	setParent(p);

}


Cell::~Cell()
{
}
