#pragma once
#include "Cell.h"
#include "GLUT.H"
#include "Colors.h"

class Maze
{
private:
	Cell* _startPoint;
	
	Cell*_targetPoint;

	Cell** _maze;

	int _size;

	void SetRandomWallsAndPassages();

	Cell* CreateAndGetMazeStartPoint();

	Cell* CreateAndGetMazeTargetPoint();

	void DrawCellSizeSqure(int row,int col);

	void SetColor(int colorNumber);


public:
	Maze(int size);

	Maze(int size,Cell* startPoint,Cell* targetPoint);

	void DrawMaze();

	void FillPointOnMaze(int x,int y);

	void CreateMaze();

	Cell* GetStartPoint() { return _startPoint; }

	Cell* GetTargetPoint() { return _targetPoint; }

	int GetMazeSize() { return _size; }

	Cell* GetCellInPosition(int row, int col) { return &  _maze[row][col]; }

	void RestorePath(Cell* node);

};
