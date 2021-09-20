/* @Author
Student Name: SENIHA SERRA BOZKURT
Student ID : 150190710 
Date: 07 DEC 2020
*/

#ifndef _H
#define _H
#include <stdio.h>

struct resistor{
	char group;
	double value;
	int quantity;
	resistor *next;
};

struct circuit{
	resistor *head;
	void create(char, double);
	void add_resistor(char, double);
	void remove_resistor(char, double);
	void delete_resistor(char, resistor*, resistor*);
	void circuit_info();
	void clear();
};

extern circuit maincircuit;
#endif