// SearchAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "SearchAlgorithm.h"
#include "Cell.h"
#include <vector>
#include <iostream>
#include "Maze.h"
#include "Colors.h"


void SearchAlgorithm::RunOnMaze(Maze* maze)
{

	if (!strategy_) 
	{
		std::cout << "Set AI algorithm strategy before run\n";
		exit(1);
	}

	_target = maze->GetTargetPoint();

	maze->GetStartPoint()->SetG(1);

	_priorityQueue.push(maze->GetStartPoint());

	StartSearchOnMaze(maze);
}


void SearchAlgorithm::StartSearchOnMaze(Maze * maze)
{	
	Cell* sampleNode;

	while (!_priorityQueue.empty())
	{
		sampleNode = _priorityQueue.top();

  		_priorityQueue.pop();

		if (sampleNode->getColor() == TARGET)
		{
			std::cout << "Solution has been found!";

			maze->RestorePath(sampleNode);

			return;
		}

		InsertNeighborsToQue(sampleNode,maze);

		sampleNode->setColor(BLACK);

	}

	std::cout << "There is no solution!";

}

void SearchAlgorithm::InsertNeighborsToQue(Cell* node,Maze* maze)
{
	int row = node->getRow();

	int col = node->getCol();

	InsertNeighborFrom(node, maze, UP);

	InsertNeighborFrom(node, maze, DOWN);

	InsertNeighborFrom(node, maze, LEFT);

	InsertNeighborFrom(node, maze, RIGHT);

	node->setColor(GRAY);

	maze->FillPointOnMaze(row, col);

}
std::tuple<int,int> GetRowAndColInDirection(int nodeRow,int nodeCol,int direction)
{
	int neighborRow, neighborCol;

	switch (direction)
	{
	case UP:
		neighborRow = nodeRow + 1;
		neighborCol = nodeCol;
		break;
	case DOWN:
		neighborRow = nodeRow - 1;
		neighborCol = nodeCol;
		break;
	case LEFT:
		neighborRow = nodeRow;
		neighborCol = nodeCol - 1;
		break;
	case RIGHT:
		neighborRow = nodeRow;
		neighborCol = nodeCol + 1;
		break;
	}

	return std::make_tuple(neighborRow, neighborCol);
}

void SearchAlgorithm::InsertNeighborFrom(Cell* node, Maze* maze, int direction)
{
	int nodeRow = node->getRow();

	int nodeCol = node->getCol();

	std::tuple neighborPosition = GetRowAndColInDirection(nodeRow, nodeCol, direction);

	int neighborRow = std::get<0>(neighborPosition);

	int neighborCol = std::get<1>(neighborPosition);

	Cell* neighbor = maze->GetCellInPosition(neighborRow, neighborCol);

	neighbor->SetG(1 + node->GetG());

	int color = neighbor->getColor();

	if (color == TARGET)
	{
		neighbor->setParent(node);

		_priorityQueue.push(neighbor);
	
		return;
	}	
	if (color == GRAY)
	{
		Cell* currentNieghborInList = *find(_blackList.begin(), _blackList.end(), neighbor);

		if (currentNieghborInList->GetF() < neighbor->GetF())
		{
			neighbor->setParent(node);

			currentNieghborInList = neighbor;

			UpdateNodePositionInPriorityQueue(node);
		}
	}
	if (color == WHITE )
	{
		_priorityQueue.push(neighbor);

		_blackList.push_back(neighbor);

		find(_blackList.begin(),_blackList.end(), neighbor);

		neighbor->setParent(node);

		neighbor->setColor(GRAY);

		maze->FillPointOnMaze(neighborRow, neighborCol);
	}
}

void SearchAlgorithm::UpdateNodePositionInPriorityQueue(Cell* node)
{
	int nodeRow = node->getRow();
	int nodeCol = node->getCol();

	Cell* currentNodeInQueue = _priorityQueue.top();
	
	std::vector<Cell*> tempNodes;


	while (currentNodeInQueue->getCol() != nodeCol && currentNodeInQueue->getRow() != nodeRow)
	{
		_priorityQueue.pop();

		tempNodes.push_back(currentNodeInQueue);

		currentNodeInQueue = _priorityQueue.top();
	}

	while (!tempNodes.empty())
	{
		_priorityQueue.push(*tempNodes.begin());

		tempNodes.erase(tempNodes.begin());
	}
}

