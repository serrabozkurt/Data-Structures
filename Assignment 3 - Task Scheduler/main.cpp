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

MultiQueue mqueue;

int main(){ //int argc, char* argv[]
	
	string process;
	int priority;

    fstream p;
	p.open("data.txt", ios::in); // 
	Queue *newque = new Queue;
	newque->init();

	while ( p >> process >> priority ) //getting the process name and priority here
	{
		Process *newprocess = new Process; //creating a new process to store the process we got
		newprocess->next = NULL;
		
		p >> newprocess->arrivaltime >> newprocess->taskcount; // getting the task count and arrival tim here

		newprocess->deadline = newprocess->arrivaltime; // at first deadline is equal to arrival time, when there are no subtasks
		newprocess->name = process; 
		newprocess->priority = priority;
		newprocess->taskstack.init(); //initializing the tasks' stack

		for (int i = 0; i < newprocess->taskcount; i++) //getting each subtask
		{ 
			Subtask *newsub = new Subtask;
            p >> newsub->name >> newsub->duration; 
			newsub->next = NULL;
			newprocess->taskstack.push(newsub);
			newprocess->deadline += newsub->duration;
		}
		newque->queue(newprocess);
	}

	mqueue.init();
	int tim = 0, spec = 0, late = 0, prbir = 0;

	while(!(*newque).isEmpty()) // adding all processes to main multiqueue
	{
		Process *ptr = newque->dequeue();
		mqueue.queues[ptr->priority - 1].queue(ptr);
	}

	while(!mqueue.isEmpty())
	{
		if((!mqueue.queues[0].isEmpty() && tim >= mqueue.queues[0].front()->arrivaltime) || (!mqueue.queues[1].isEmpty() && tim >= mqueue.queues[1].front()->arrivaltime) || (!mqueue.queues[2].isEmpty() && tim >= mqueue.queues[2].front()->arrivaltime)){
			

			//processes with priority 1
			while(!mqueue.queues[0].isEmpty() && tim >= mqueue.queues[0].front()->arrivaltime)
			{
				Process *tmp = mqueue.queues[0].front();
				Subtask *tmpsub = tmp->taskstack.pop();

				tim += tmpsub->duration;
				cout<<tmp->name<<" "<<tmpsub->name<<endl;
				tmp->taskcount -= 1;

				if (tmp->taskcount == 0){ // if executed all the subtasks remove that process from the queue
					late += (tim - tmp->deadline);
					mqueue.queues[0].dequeue();
				}
			}
			prbir = 0;

			//processes with priority 2
			while(!mqueue.queues[1].isEmpty() && tim >= mqueue.queues[1].front()->arrivaltime && (spec<2 || (spec >= 2 && (!mqueue.queues[2].isEmpty() && tim < mqueue.queues[2].front()->arrivaltime))))
			{
				
				Process *tmp = mqueue.queues[1].front();
				Subtask *tmpsub = tmp->taskstack.pop();

				tim += tmpsub->duration;
				cout<<tmp->name<<" "<<tmpsub->name<<endl;
				tmp->taskcount -= 1;

				if (tmp->taskcount == 0){ // if executed all the subtasks remove that process from the queue
					late += (tim - tmp->deadline);
					mqueue.queues[1].dequeue();
				}
				spec++;

				if(!mqueue.queues[0].isEmpty() && tim >= mqueue.queues[0].front()->arrivaltime){
					prbir = 1;
					break;
				}
				if (spec>=2 && (!mqueue.queues[2].isEmpty() && tim >= mqueue.queues[2].front()->arrivaltime)){
					break;
				}
			}

			//processes with priority 3
			while(!mqueue.queues[2].isEmpty() && tim >= mqueue.queues[2].front()->arrivaltime && prbir == 0)
			{
				spec=0;
				
				Process *tmp = mqueue.queues[2].front();
				Subtask *tmpsub = tmp->taskstack.pop();

				tim += tmpsub->duration;
				cout<<tmp->name<<" "<<tmpsub->name<<endl;
				tmp->taskcount -= 1;

				if (tmp->taskcount == 0){ // if executed all the subtasks remove that process from the queue
					late += (tim - tmp->deadline);
					mqueue.queues[2].dequeue();
				}
				
				if((!mqueue.queues[0].isEmpty() && tim >= mqueue.queues[0].front()->arrivaltime)||(!mqueue.queues[1].isEmpty() && tim >= mqueue.queues[1].front()->arrivaltime)){
					break;
				}
			}
		}

		else
		{
			tim++; //if time is behind any process, we just increase it
		}
	}

	cout<<"Cumulative Lateness: "<<late;
	getchar();
	p.close();
	return 0;
}

/* @Author
Student Name: SENIHA SERRA BOZKURT
Student ID : 150190710 
Date: 09 JAN 2021
*/