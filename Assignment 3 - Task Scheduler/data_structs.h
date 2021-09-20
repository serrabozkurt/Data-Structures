/* @Author
Student Name: SENIHA SERRA BOZKURT
Student ID : 150190710 
Date: 09 JAN 2021
*/

#ifndef _H
#define _H
#include <stdio.h>
using namespace std;


struct Subtask{
	string name;
	int duration;
	Subtask* next;
	};

struct Stack{
	Subtask* head;
	void init();
	void close();
	void push(Subtask* in);
	Subtask* pop();
	bool isEmpty();
	};

struct Process{
	string name;
	int arrivaltime, deadline, taskcount, priority;
	Stack taskstack;
	Process* next;
	};



struct Queue{
	Process* head;
	Process* tail;
	void init();
	void close();
	void queue(Process* in);
	Process* dequeue();
	bool isEmpty();
	Process* front();
	};

struct MultiQueue{
	Queue queues[3];
	void init();
	void close();
	void queue(Process* in);
	Process* dequeue(int priority);
	bool isEmpty();
	Process* front(int priority);
	};

extern MultiQueue mqueue;
#endif