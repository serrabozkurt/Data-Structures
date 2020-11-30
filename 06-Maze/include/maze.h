#pragma once
#include <iostream>
using namespace std;

struct Position{
	int x;
	int y;
	int right;
	int left;
	int down;
	int up;	
	int camefrom;
};

#define RIGHT   1
#define LEFT    2
#define UP      3
#define DOWN    4
#define MAZE_HOR_SIZE    8
#define MAZE_VER_SIZE    8

void printmaze(char maze[MAZE_HOR_SIZE][MAZE_VER_SIZE]){
    for (int i = 0; i < MAZE_HOR_SIZE; i++) {
        for (int j = 0; j < MAZE_VER_SIZE; j++)
            cout << maze[i][j];
        cout << endl;
    }
    cout << endl << endl;
}