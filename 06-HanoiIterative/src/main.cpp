#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#define NUM_OF_DISKS 3
using namespace std;

void hanoi_iterative(int, Stack<int>[3]);

int main()
{
	
	Stack<int> s[3];

	for (int i = 0; i < 3; i++)
		s[i].create();

	for (int i = 0; i < 5; i++)
		s[0].push(NUM_OF_DISKS - i);

	hanoi_iterative(NUM_OF_DISKS, s);

	for (int i = 0; i < 3; i++)
		s[i].close();

	getchar();
	return EXIT_SUCCESS; 
}

void hanoi_iterative(int n, Stack<int> s[3])
{
	Stack<StackMoveType> m;
	m.create();
	StackMoveType move = {n, 0, 2};
	m.push(move);
	while (!m.isempty())
	{
		move = m.pop();
	
		if(move.n==1)
			cout << "From: "<< move.source << " To: " << move.destination << endl ;
	
		if (move.n == 1) s[move.destination].push(s[move.source].pop());
		else
		{
			int temp = 0 + 1 + 2 - move.destination - move.source;
			StackMoveType newmove = {move.n - 1, temp, move.destination};
			m.push(newmove);
			newmove.n = 1;
			newmove.source = move.source;
			newmove.destination = move.destination;
			m.push(newmove);
			newmove.n = move.n - 1;
			newmove.source = move.source;
			newmove.destination = temp;
			m.push(newmove);
		}
	}
	m.close();
}
