#pragma once
#include <queue>
#include <vector>
#include <math.h>
#include "Maze.h"
#include "Cell.h"
#include "CellsComperator.h"
#include "ComputeFStrategy.h"


const int UP = 0;
const int DOWN = 1;
const int LEFT = 2;
const int RIGHT = 3;

class SearchAlgorithm
{
private:

	Cell* _target;

	std::priority_queue < Cell*, std::vector<Cell*>, CellsComperator> _priorityQueue;

	std::vector<Cell*> _blackList;

	void StartSearchOnMaze(Maze* maze);

	void InsertNeighborFrom(Cell* node,Maze* maze, int direction);

	void UpdateNodePositionInPriorityQueue(Cell* node);

	std::unique_ptr<ComputeFStrategy> strategy_;
	

public:

	SearchAlgorithm() {};

	~SearchAlgorithm() {};

	void setComputeFStrategy(std::unique_ptr<ComputeFStrategy> &&strategy)
	{
		strategy_ = std::move(strategy);
	}

	void RunOnMaze(Maze* maze);

	void InsertNeighborsToQue(Cell* node,Maze* maze);
};
