#include "LinkedList.h"
#ifndef HEADERFILE_H
#define HEADERFILE_H
#include <iostream>
#include <string>
#endif
using namespace std;
/*Write the necessary C++ data structures and methods in order to execute question3.
Please  also keep in mind that your code must have no memory leaks.
So please also provide extra methods which are necessary to escape memory leaks
although not invoked within the below function.
*/

Linkedlist newlist;

void Linkedlist::create(){
	newlist.head = new node;
	newlist.head->next = NULL;
}

void Linkedlist::add2beginning(int i){
	node* temp;
	temp = new node;
	temp->data = i;
	temp->next = newlist.head;
	newlist.head = temp;
	//delete temp; ////////////////7
}

void Linkedlist::clear()
{
	while (newlist.head)
    {
		node* temp;
        temp = newlist.head;
        newlist.head = newlist.head->next;
        delete temp;
    }
}

void Linkedlist::printt(){
	node* temp;
	temp = newlist.head;
	while(temp->next){
		cout<<temp->data;
		temp = temp->next;
	}
}

void question3(){
	Linkedlist l;
	l.create();
	for (int i = 0; i < 4; i++)
		l.add2beginning(i); 
	//l.prtt(); 
	l.clear();
}

/* @Author
Student Name: SENIHA SERRA BOZKURT
Student ID : 150190710 
Date: 08 DEC 2020
*/