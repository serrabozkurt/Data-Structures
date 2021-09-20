/* @Author
Student Name: SENIHA SERRA BOZKURT
Student ID : 150190710 
Date: 07 DEC 2020
*/

#include <iostream> 
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include <fstream>

#include "circuit.h"
using namespace std;

circuit maincircuit;

void circuit::create(char group, double value){
	
	maincircuit.head = new resistor;

	maincircuit.head->group = group;
	maincircuit.head->value = value;
	maincircuit.head->quantity = 1;
	maincircuit.head->next = NULL;
}

void circuit::add_resistor(char group, double value){

	if (!maincircuit.head){ // if we havent added any maincircuit.head node
		maincircuit.create(group, value);
		return;
	}

	resistor* newresistor; // creating a node to add to list
	newresistor = new resistor;
	newresistor->group = group; newresistor->value = value; newresistor->quantity = 1; newresistor->next = NULL;

	if(maincircuit.head->group > group){ // add to head
		newresistor->next = maincircuit.head;
		maincircuit.head = newresistor;
		return;
	}

	resistor* curNode = maincircuit.head;
	resistor* parent = curNode;

	while(curNode && (group > curNode->group)) { // traverse through list 
		parent = curNode;
		curNode = curNode->next;
	}

	if(curNode){ // if we are somewhere in the middle of the list
		if (curNode->group == group){ // if that group exists
			curNode->quantity += 1; 
			return;
		}
		// if that group does not exist, we should add the group to list 
		newresistor->next = curNode; 
		parent->next = newresistor;
	}
	else{ // if we are in the end
		parent->next = newresistor;
	}
}

void circuit::delete_resistor(char group, resistor* curNode, resistor* parent){
	parent->next = curNode->next; // we are directing the parent to child, so the middle node be out of list
	curNode->next = NULL;
	delete curNode; // deleting the current
}

void circuit::remove_resistor(char group, double value)
{
	resistor* ptr;
	resistor* parent;
	ptr = maincircuit.head;

	while((ptr->group != group) && ptr->next){
		parent = ptr;
		ptr = ptr->next;
	}
	if(ptr->group == group){

		ptr->quantity -= 1;
		if(ptr->quantity == 0){
			maincircuit.delete_resistor(group, ptr, parent);
		}
	}
	else{
		cout<<"NO_RESISTOR"<<endl;
	}
}

resistor* resistances;

void circuit::circuit_info(){
	double resistance = 0;

	resistances = new resistor;
	resistances->next = NULL; 
	resistances->value = maincircuit.head->value; 
	resistances->quantity = maincircuit.head->quantity;
	
	resistor* ptr1;
	//ptr1 = resistances;

	resistor* ptr2;
	ptr2 = maincircuit.head->next;

	resistor* parent;

	while(ptr2){

		resistor* newresistor = new resistor; // creating a node to add to list
		newresistor->value = ptr2->value; 
		newresistor->quantity = ptr2->quantity; 
		newresistor->next = NULL;

		if(resistances->value > ptr2->value){ // add to head
			newresistor->next = resistances;
			resistances = newresistor;
		}
		else {
			ptr1 = resistances;
			parent = ptr1;

			while(ptr1 && (newresistor->value > ptr1->value)) { // traverse through list 
				parent = ptr1;
				ptr1 = ptr1->next;
			}

			if(ptr1){ // we should add the resistance/s to list if we are in the middle somewhere
				newresistor->next = ptr1;
				parent->next = newresistor;
			}
			else{ // if we are in the end
				parent->next = newresistor;
			}
		}
		ptr2 = ptr2->next;
	}

	ptr1 = resistances;

	while(ptr1){
		double res = ptr1->value; int q = ptr1->quantity;
		resistance += (double)((double)(ptr1->value)/(double)(ptr1->quantity));

		while(ptr1->next && (ptr1->next->value == ptr1->value)){
			ptr1 = ptr1->next;
			q += ptr1->quantity;
			resistance += (double)((double)(ptr1->value)/(double)(ptr1->quantity));
		}
		cout << res << ":" << q << endl;
		
		ptr1 = ptr1->next;
	}
	cout << "Total resistance=" << resistance << " ohm" << endl;

	ptr1 = resistances->next;

	while(ptr1){
		resistor* todelete;
		todelete = ptr1;
		ptr1 = ptr1->next;
		delete todelete;
	}
}

void circuit::clear(){

	resistor* ptr;
	ptr = maincircuit.head->next;

	while(ptr){
		resistor* todelete;
		todelete = ptr;
		ptr = ptr->next;
		delete todelete;
	}
	delete ptr;
}

int main(int argc, char* argv[]){
	
	char group;
    double value;
	
    fstream p;
	p.open(argv[1], ios::in); // BUNU ARGV *!!!*

	while ( p >> group >> value ){

		if(group == 'A' && value == 0){
			maincircuit.circuit_info();
		}
		else if(value < 0){
			maincircuit.remove_resistor(group, value);
		}
		else{
			maincircuit.add_resistor(group, value);
		}
	}
	maincircuit.clear();
	return 0;
}

/* @Author
Student Name: SENIHA SERRA BOZKURT
Student ID : 150190710 
Date: 07 DEC 2020
*/
