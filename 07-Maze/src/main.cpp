#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "maze.h"
using namespace std;

char maze[MAZE_HOR_SIZE][MAZE_VER_SIZE] = {{'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
										   {' ', ' ', 'x', 'x', 'x', ' ', ' ', ' '},
										   {'x', ' ', 'x', 'x', 'x', ' ', 'x', 'x'},
										   {'x', ' ', ' ', ' ', ' ', ' ', ' ', 'x'},
										   {'x', ' ', 'x', ' ', 'x', 'x', ' ', 'x'},
										   {'x', ' ', 'x', 'x', ' ', 'x', ' ', 'x'},
										   {'x', ' ', ' ', 'x', ' ', ' ', ' ', 'x'},
										   {'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'}};

int main()
{
	Stack<Position> s;
	s.create();
	Position entrance = {0, 1, 0, 0, 0, 0, 0};
	Position exit = {7, 1, 0, 0, 0, 0, 0};
	Position p = entrance;
	p.camefrom = LEFT;
	printmaze(maze);
	bool goback = false;

	while (p.x != exit.x || p.y != exit.y)
	{
		maze[p.y][p.x] = 'o';
		printmaze(maze);
		getchar();
		//first find in how many directions we can move
		if (!goback)
		{ //if not calculated before
			p.right = 0;
			p.left = 0;
			p.down = 0;
			p.up = 0;
			if (p.x < 7 && maze[p.y][p.x + 1] != 'x')
				p.right = 1; //right
			if (p.x > 0 && maze[p.y][p.x - 1] != 'x')
				p.left = 1; //left
			if (p.y < 7 && maze[p.y + 1][p.x] != 'x')
				p.down = 1; //down
			if (p.y > 0 && maze[p.y - 1][p.x] != 'x')
				p.up = 1; //up
		}
		else
			goback = false;
		//here, one of the possible moves is selected
		bool moved = true;
		Position past = p;
		if (p.down && p.camefrom != DOWN)
		{
			p.y++;
			p.camefrom = UP;
			past.down = 0;
		}
		else if (p.up && p.camefrom != UP)
		{
			p.y--;
			p.camefrom = DOWN;
			past.up = 0;
		}
		else if (p.left && p.camefrom != LEFT)
		{
			p.x--;
			p.camefrom = RIGHT;
			past.left = 0;
		}
		else if (p.right && p.camefrom != RIGHT)
		{
			p.x++;
			p.camefrom = LEFT;
			past.right = 0;
		}
		else
			moved = false; //one direction (the minimum) is open, but this is the direction we came from
		if (p.x != exit.x || p.y != exit.y)
		{
			if ((past.down + past.up + past.right + past.left) > 1)
			{
				//there is more than one choice, push onto stack and //continue in that chosen direction. Let the choices  //you have not selected remain marked on the stack.
				s.push(past);
			}
			if (!moved)
			{ // has to go back
				if (!s.isempty())
				{
					p = s.pop();
					goback = true;
				}
			}
		}
	} //end of while
	maze[p.y][p.x] = 'o';
	printmaze(maze);
	cout << "PATH found" << endl;
	s.close();

	getchar();
	return EXIT_SUCCESS;
}
