#pragma once
#include "Colors.h"


class Cell
{

private:
	int row;
	int col;
	int Color;
	int _h = -1;
	int _g = -1;

	Cell* SourceParent;
	Cell* TargetParent;
public:
	Cell();
	Cell(int r, int c);
	Cell(int r, int c, Cell * p);
	Cell(int r, int c, int color);
	Cell(int r, int c,int color, Cell * p);
	~Cell();
	int getRow() { return row; }
	int getCol() { return col; }
	int getColor() { return Color; }
	void setRow(int r) { row = r; }
	void setCol(int c) { col = c; }
	void setColor(int color)
	{ 
		Color = color; 
	}

	void SetH(int h) { _h = h; }

	void SetG(int g) { _g = g; }

	int GetF() { return _h + _g; }
	int GetG() { return _g; }

	void setParent(Cell* parent)
	{ 
		if (Color == BLACK_BY_SOURCE || Color == GRAY_BY_SOURCE)
		{
			SourceParent = parent;
		}
		else
		{
			TargetParent = parent;
		}
	}
	void setSourceParent(Cell* parent) { SourceParent= parent; }
	void setTargetParent(Cell* parent) {TargetParent = parent;}

	Cell* getSourceParent() { return SourceParent; }
	Cell* getTargetParent() { return TargetParent; }
};


