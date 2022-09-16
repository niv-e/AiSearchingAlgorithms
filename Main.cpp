// BidirectionalBFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Best First Search is a greedy algorithm for path finding
Its base on a priority queue and hiuristic function that infrom
the algorithm who is the best node to reach the goal node
*/
using namespace std;

#include "helperFuncs.h"
#include "GLUT.h"
#include "Cell.h"
#include <time.h>
#include <vector>
#include <queue>
#include "Maze.h"
#include "Main.h"
#include "BestFirstSearch.h"
#include "SearchAlgorithm.h"
#include "AStarStrategy.h"
#include <future>



bool befs_is_running = false;
bool Astar_is_running = false;
int mazeSize = 100;
Maze* _maze;

void main(int argc, char* argv[])
{
	InitializeDisplayComponents(argc, argv);

	CreateDisplayManu();

	srand(time(0)); // seed random numbers

	glClearColor(0, 0, 0.2, 0); // RGB - sets background color

	glOrtho(0, mazeSize, 0, mazeSize, -1, 1); // setup coordinate system
	 
	_maze = new Maze(mazeSize);

	_maze->CreateMaze();

	_maze->DrawMaze();

	glutMainLoop();

}


void InitializeDisplayComponents(int argc, char* argv[])
{
	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // double means it uses double buffer
	
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HIEGHT);
	
	glutInitWindowPosition(600, 100);


}

void CreateDisplayManu()
{
	glutCreateWindow("AI_Search_Algorithms");
	
	glutDisplayFunc(display); // refresh function
	
	glutIdleFunc(idle); // runs all the time in the background
	
	glutCreateMenu(menu);// add menu
	
	glutAddMenuEntry("Run BestFirstSearch", 1);
	glutAddMenuEntry("Run Astar", 2);
	
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void menu(int choice)
{
	switch (choice)
	{
	case 1: // bfs
		befs_is_running = true;
		break;
	case 2: // bfs
		Astar_is_running = true;
		break;
	}
}

void idle()
{

	if (befs_is_running)
	{

		SearchAlgorithm* searchAlgorithm = new SearchAlgorithm();

		searchAlgorithm->setComputeFStrategy(std::make_unique <BestFirstSearchStrategy >());

		std::future<void> algurithmExecuter = std::async(launch::async, &SearchAlgorithm::RunOnMaze, searchAlgorithm, _maze);

		befs_is_running = false;
	}
	if (Astar_is_running)
	{
		SearchAlgorithm* searchAlgorithm = new SearchAlgorithm();

		searchAlgorithm->setComputeFStrategy(std::make_unique <AStarStrategy>());

		std::future<void> algurithmExecuter = std::async(launch::async, &SearchAlgorithm::RunOnMaze, searchAlgorithm, _maze);

		Astar_is_running = false;
	}
	glutPostRedisplay(); // calls indirectly to display
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT); // fills all the frame buffer with background color
	
  	_maze->DrawMaze();

	glutSwapBuffers();// show what was drawn in "frame buffer"
}

