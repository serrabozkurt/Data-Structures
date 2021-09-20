/* @Author
Student Name: SENIHA SERRA BOZKURT
Student ID : 150190710 
Date: 09 JAN 2021
*/

#include <iostream> 
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include <fstream>

#include "data_structs.h"
using namespace std;

void Stack::init()
{
    head = NULL;
}

void Stack::close()
{
    Subtask* tmp;
    while (head){
        tmp = head;
        head = head->next;
        delete tmp;
    }
}

void Stack::push(Subtask* to_pushed)
{
    to_pushed->next = head;
    head = to_pushed;
}

Subtask* Stack::pop()
{ 
    Subtask *top;
    top = head;
    head = head->next;
    return top;
}

bool Stack::isEmpty()
{
    return head == NULL;
}

void Queue::init()
{
    head = NULL;
    tail = NULL;
}

void Queue::close()
{
    Process* temp;
    while(head){
        temp = head;
        head = head->next;
        delete temp;
    }
}

void Queue::queue(Process* newqq)
{
    newqq->next = NULL;

	if (isEmpty()) 
    { 
		tail = newqq;
		head = tail;
	} else {
		tail->next = newqq;
		tail = newqq;
	}
}

Process* Queue::dequeue()
{ 
    Process *top = head;
	head = head->next;
	if(head == NULL)
		tail = NULL;
    
	return top;
}

bool Queue::isEmpty()
{
    return head == NULL;
}

Process* Queue::front()
{    
    return head;
}

void MultiQueue::init(){    
    queues[0].init();
    queues[1].init();
    queues[2].init();
}

void MultiQueue::close()
{
    queues[0].close();
    queues[1].close();
    queues[2].close();
}

void MultiQueue::queue(Process* newqq)
{
    if (queues[newqq->priority].isEmpty()) 
    { 
		queues[newqq->priority].tail = newqq;
		queues[newqq->priority].head = queues[newqq->priority].tail;
	} else {
		queues[newqq->priority].tail->next = newqq;
		queues[newqq->priority].tail = newqq;
	}
}

Process* MultiQueue::dequeue(int priority)
{
    Process *top;
	top = queues[priority-1].head;
	queues[priority-1].head = queues[priority-1].head->next;
	if(queues[priority-1].head == NULL)
		queues[priority-1].tail = NULL;
	return top;
}

bool MultiQueue::isEmpty()
{
    if(queues[0].isEmpty() && queues[1].isEmpty() && queues[2].isEmpty()){
        return true;
    }
    return false;

}

Process* MultiQueue::front(int priority)
{
    return queues[priority-1].front();
}

/* @Author
Student Name: SENIHA SERRA BOZKURT
Student ID : 150190710 
Date: 09 JAN 2021
*/
