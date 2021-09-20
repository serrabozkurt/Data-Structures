/*
STUDENT NAME: SENIHA SERRA BOZKURT
STUDENT ID: 150190710
CLASS: BLG 223E - CRN: 11624
*/

#ifndef _H
#define _H
#include <stdio.h>

#define ARRAY_SIZE 100

#include "token.h"


struct Counter{
	int token_count=0;
	Token token_array[ARRAY_SIZE];
	void read_and_count();
	bool contains(char *,char);
	int findindex(Token [],char[]);
	Token *get_most_common_three();
};
extern Counter counter;
#endif
