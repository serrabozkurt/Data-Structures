#include <iostream>
#include <fstream>
#include <string>
#include <string.h>				   
#include <queue>
using namespace std;
/*
STUDENT NAME: SENIHA SERRA BOZKURT
STUDENT ID: 150190710
CLASS: BLG 223E - CRN: 11624
*/
/*Assuming that you are given l2->head sorted singly linked list, whose data structures and creation methods are provided below, you are asked to 
write a mergeList function which will create a new sorted linked list from the input lists' elements.
mergeList takes 3 arguments (adresses of Linked List structures), where the first 2 are the input linked lists and the 3rd l1->head is the 
output linked list. Your program shouldn't take any new memory but rather use the nodes of the input lists and link them to each other.
After the operation, the original lists' will be empty.
The signature of the method and the main function are provided. 
You are NOT allowed to change the main function. Please only fill in
the body part of the mergeList method. Writing extra methods to existing structures is allowed but they could  only be invoked by the mergeList function.
A sample input file (input.txt with an empty line between the l2->head linked lists' elements) and a sample output message are provided. Your code will be tested with similar inputs.
Attention: if the same number appears in both of the input list, it should appear only ONCE in the last list. In such a case, Don't forget to delete the unnecessary (extra) node.
The given input file should produce the following output:*/
struct Node{
	int data;
	Node *next;
};
struct LinkedList{
	Node *head, *tail;
	void add(int);
	
	void create();
	void print();
};
void LinkedList::create(){
	head = NULL; tail = NULL;
}
void LinkedList::print(){
	Node *t = head;
	while (t){
		cout << t->data << " ";
		t = t->next;
	}
}
void LinkedList::add(int indata){
	Node *newnode = new Node;
	newnode->data = indata;
	newnode->next = NULL;
	if (head == NULL){
		head = newnode;
		tail = newnode;
		return;
	}
	tail->next = newnode;
	tail = newnode;
}

void mergeList(LinkedList *l1, LinkedList *l2, LinkedList *l3){
	Node *merged;

	if(!l1->head)
		l3 = l2;
	else if (l1->head && !l2->head)
		l3 = l1;
	else{

		if(l1->head->data > l2->head->data){
			l3->head = l2->head;
			l2->head = l2->head->next;
		}
		else if(l1->head->data < l2->head->data){
			l3->head = l1->head;
			l1->head = l1->head->next;
		}
		else{
			l3->head = l1->head;
			l1->head = l1->head->next;
			l2->head = l2->head->next;
		}
		merged = l3->head;
		while(l1->head && l2->head){
			if(l1->head->data > l2->head->data){
				merged->next = l2->head;
				l2->head = l2->head->next;
			}
			else if(l1->head->data < l2->head->data){
				merged->next = l1->head;
				l1->head = l1->head->next;
			}
			else{
				merged->next = l1->head;
				l1->head = l1->head->next;
				l2->head = l2->head->next;
			}
			merged = merged->next;
		}
		if(l1->head){
			merged->next = l1->head;
			while(l1->head){
				l1->head = l1->head->next;
			}
		}
		if(l2->head){
			merged->next = l2->head;
			while(l2->head){
				l2->head = l2->head->next;
			}
		}
		
	}
	
	
}
int main(int argc, char* argv[]){
	LinkedList myl1, myl2, myl3;
	myl1.create(); myl2.create(); myl3.create();
	string line;
	string filepath="inputQ2.txt";
	if (argc>1)
	{
	filepath=argv[1];
	}
	ifstream myfile(filepath);
	if (myfile.is_open())
	{
		while (getline(myfile, line) && line!="" && line!="\r")
		{
			myl1.add(stoi(line));
		}
		while (getline(myfile, line) && line!="" && line!="\r")
		{
			myl2.add(stoi(line));
		}
		myfile.close();
	}
	else cout << "Unable to open file";

	myl1.print();
	cout << endl << "####" << endl;
	myl2.print();
	cout << endl << "####" << endl;

	mergeList(&myl1,&myl2,&myl3);

	myl1.print();
	cout << endl << "####" << endl;
	myl2.print();
	cout << endl << "####" << endl;
	myl3.print();
	//getchar();
	return 0;		
}
