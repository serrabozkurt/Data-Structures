#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

typedef char QueueDataType;

struct Node{               
	QueueDataType data;
	Node *next;
};

struct Queue {
	Node *front;
	Node *back;	
	void create();
	void close();
	void print_queue();
	void enqueue(QueueDataType);
	QueueDataType dequeue();
	bool isempty();
};

void Queue::create(){
	front = NULL; 
	back = NULL;
}
void Queue::close(){
	Node *p;
	while (front) {
		p = front;
		front = front->next;
		delete p;
	}
}
void Queue::enqueue(QueueDataType newdata){
	Node *newnode = new Node;
	newnode->data = newdata;
	newnode->next = NULL;
	if ( isempty() ) {    // first element?
		back = newnode;
		front = back;
	}
	else {
		back->next = newnode;
		back = newnode;
	}

}

QueueDataType Queue::dequeue() {
	Node *topnode;
	QueueDataType temp;
	topnode = front;
	front = front->next;
	temp = topnode->data;	
	delete topnode;
	return temp;
}
bool Queue::isempty() {
	return front == NULL;
}
    
void Queue::print_queue(){
	Node *p=front;
	cout << "[ ";
	while (p) {
		cout << p->data << " ";
		p = p->next;
	}
	
	cout << "]" << endl;
}
