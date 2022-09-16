#include "Maze.h"



Maze::Maze(int size)
{
	_size = size;

	_maze = new Cell*[size];

	for (int i = 0; i < size; i++)
	{
		_maze[i] = new Cell[size];
		
		for (int j = 0; j < size; j++)
		{
			_maze[i][j].setRow(i);
			_maze[i][j].setCol(j);
		}
	}
}

Maze::Maze(int size, Cell * startPoint, Cell * targetPoint) : Maze(size)
{
	_startPoint = startPoint;

	_targetPoint = targetPoint;
}


void Maze::CreateMaze()
{
	SetRandomWallsAndPassages();

	if (_startPoint == nullptr)
	{
		_startPoint = CreateAndGetMazeStartPoint();

		FillPointOnMaze(_startPoint->getRow(), _startPoint->getCol());
	}
	if (_targetPoint == nullptr)
	{
		_targetPoint = CreateAndGetMazeTargetPoint();

		FillPointOnMaze(_targetPoint->getRow(), _targetPoint->getCol());
	}
}

void Maze::RestorePath(Cell * node)
{
	Cell* parent = node->getTargetParent();
	
	int parentRow = parent->getRow();
	
	int parentCol = parent->getCol();

	while (parent != nullptr)
	{
		parentRow = parent->getRow();

		parentCol = parent->getCol();

		_maze[parentRow][parentCol].setColor(PATH);

		FillPointOnMaze(parentRow, parentCol);
	
		parent = parent->getTargetParent();
	}
}

Cell* Maze::CreateAndGetMazeStartPoint()
{
	Cell* startPoint = new Cell(_size / 2, _size / 2, START);

	_maze[_size / 2][_size / 2] = *startPoint;

	return startPoint;
}

Cell* Maze::CreateAndGetMazeTargetPoint()
{

	//int targetRowPositon = rand() % _size;

	//int targetColPositon = rand() % _size;

	int targetRowPositon = _size / 2 + 20;

	int targetColPositon = _size / 2 + 20;

	Cell* targetPoint = new Cell(targetRowPositon, targetColPositon, TARGET);
	
	_maze[targetRowPositon][targetColPositon] = *targetPoint;

	return targetPoint;

}


void Maze::SetRandomWallsAndPassages()
{
	int row, col;
	// the border is WALL by default 
	for (row = 1; row < _size - 1; row++)
	{
		for (col = 1; col < _size - 1; col++)
		{
			if (row % 2 == 1) // more SPACES
			{
				if (rand() % 100 < 85)
					_maze[row][col].setColor(SPACE);
				else
					_maze[row][col].setColor(WALL);
			}
			else // i is even: more walls
			{
				if (rand() % 100 < 30)
					_maze[row][col].setColor(SPACE);
				else
					_maze[row][col].setColor(WALL);
			}

		}
	}
}

void Maze::DrawMaze()
{
	int i, j;

	int startRow = _startPoint->getRow();
	int startCol = _startPoint->getCol();
	int targetRow = _targetPoint->getRow();
	int targetCol = _targetPoint->getCol();
	_maze[startRow][startCol].setColor(START);
	_maze[targetRow][targetCol].setColor(TARGET);

	for (i = 0; i < _size; i++)
	{
		for (j = 0; j < _size; j++)
		{
			FillPointOnMaze(i,j);
		}
	}
}

void Maze::DrawCellSizeSqure(int row, int col)
{
	glBegin(GL_POLYGON);
	glVertex2d(col, row);
	glVertex2d(col, row + 1);
	glVertex2d(col + 1, row + 1);
	glVertex2d(col + 1, row);
	glEnd();
	glutPostRedisplay();

}

void Maze::FillPointOnMaze(int row, int col)
{
	SetColor(_maze[row][col].getColor());

	DrawCellSizeSqure(row, col);
}

void Maze::SetColor(int colorNumber)
{
	switch (colorNumber)
	{
	case WALL:
		glColor3d(0.3, 0, 0);// dark red
		break;
	case SPACE:
		glColor3d(1, 1, 1); // white
		break;
	case START:
		glColor3d(0.5, 0.7, 1);// light blue
		break;
	case TARGET:
		glColor3d(1, 0, 0); // red
		break;
	case GRAY:
		glColor3d(51, 204, 51); // light green
		break;
	case BLACK:
		glColor3d(0, 51, 0); // dark green
		break;
	case PATH:
		glColor3d(0.7, 0, 0.7); // magenta
		break;
	}
}
