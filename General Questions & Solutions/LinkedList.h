/* @Author
Student Name: SENIHA SERRA BOZKURT
Student ID : 150190710 
Date: 08 DEC 2020
*/
#pragma once

struct node{
	int data;
    node* next;
};

struct Linkedlist{
	node* head;
    void create();
    void add2beginning(int);
    void clear();
    void printt();
};

void question3();

