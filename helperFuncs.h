#pragma once

#include "Cell.h"

const int WINDOW_WIDTH = 600;
const int WINDOW_HIEGHT = 600;
const int MAZE_SIZE = 50;

void init();

void menu(int choice);

void idle();

void display();


void BfsIteration();

void VisitNeighbors(Cell* node);

void RestorPath(Cell* node);

void CreatAndPushNeighborToQueue(int row, int col, int parentColor, Cell* parent);

bool IsSpace(int row, int col);

bool IsGrayByOther(int row, int col, int color);

int GetCorrispondingGrayColor(int color);

void SetColor(int row, int col);

Cell* prepareToResorePath(int row, int col, int parentColor, Cell* parent);

