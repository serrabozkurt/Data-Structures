//25 pts
/*Write the multilist struct where the node structure is given. 
Each node should have two pointers (next and root).
Each node's next pointer will point to the
next integer in the list as usual.
The list should be sorted in ascending order.
If a number has an integer root (e.g. 9's root is 3 which is an integer)
its node's root pointer should point to its root's node  otherwise it should be NULL.
write the methods returnadressof and add.
The add method should add n numbers from 1 to n (the function input argument) to the multilist.
e.g. when the argument is 100 it will add 100 numbers with a single function call.
You may assume that the multilist will always be empty when the add method is called.
The root pointer of the node carrying "1" should always be  NULL.
hint you may use the sqrt and floor methods from <math.h>.
*/

#include "SortedMultiList.h"
#ifndef HEADERFILE_H
#define HEADERFILE_H
#include <iostream>
#include <string.h>
#include <math.h>
#endif
using namespace std;

Multilist l;

void Multilist::add(int n){
	if(l.headptr == NULL){
		l.headptr = new mnode;
		l.headptr->data = 1;
		l.headptr->root = NULL;
		l.headptr->next = NULL;
	}
	
	if(n==1){
		return;
	}
	else if(n == 0){
		delete l.headptr;
		return;
	}

	mnode* ptr;
	ptr = l.headptr;

	for (int i = 2; i<=n; i++){
		ptr->next = new mnode;
		ptr->next->data = i;
		ptr->next->next = NULL;
		int x = sqrt(i);

		if(i == x*x){
			mnode* temp2 = l.headptr;
			while(temp2->data != x){
				temp2 = temp2->next;
			}
			ptr->next->root = temp2;
		}
		else{
			ptr->next->root = NULL;
		}
		ptr = ptr->next;
	}
}


mnode* Multilist::returnadressof(int start){
	mnode* ptr=l.headptr;
	while(ptr->data != start){
		ptr = ptr->next;
	}
	return ptr;
}

void question4(){
	Multilist l;
	l.create();
	l.add(10000);
	l.printroots(l.returnadressof(6561));//will print "6561 81 9 3 \n" accordingly
}

void Multilist::printroots(mnode *start){
	while (start != NULL){
		cout << start->data << " ";
		start = start->root;
	}
	cout << endl;
}

void Multilist::create(){
	headptr = NULL;
}
