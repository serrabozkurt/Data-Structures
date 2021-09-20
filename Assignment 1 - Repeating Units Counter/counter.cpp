/*
STUDENT NAME: SENIHA SERRA BOZKURT
STUDENT ID: 150190710
CLASS: BLG 223E - CRN: 11624
*/

#include <iostream>
#include <stdlib.h>
#include <string.h>

#include "counter.h"

using namespace std;


int Counter::findindex(Token *arr,char elem[]){
	int i;
	for(i = 0; i < counter.token_count; i++){ //this for loop looks for the token in token array
		if(!strcmp(counter.token_array[i].token, elem)){ 
			return i; //if it finds, returns the index
		}
	}
	return -1; // if such token doesn't exist, function gets out of the loop and returns -1
} 

bool Counter::contains(char *token, char target){

	if(*token == target || *(token + 1) == target){ //checks if the target is included in the token
		return true; //if the target is included in the token, returns true
	}

	return false; //else gets out of that loop and returns false
}


void Counter::read_and_count(){

	FILE *pi_file = fopen("pi_approximate", "r"); // open pi file
	char pi_array[1000005]; // initialize an array
	fgets(pi_array, 1000005, pi_file); // write file into array
	int pi_length = strlen(pi_array), i, came_to_decimal = 0; 
	pi_array[pi_length] = '\0'; // end the pi array with ending element
	Token token_arr[100]; // initialize a temporary token array

	for(i = 0; i < pi_length - 1; i++){ // fill the temporary token array with tokens

		if(contains(pi_array+i, '.') || contains(pi_array+i, ',') || contains(pi_array+i, '\n')){
			came_to_decimal = 1;
			i++;
			continue;
		}

		if(!came_to_decimal){ // if w haven't arrived to decimal point yet, keep looking for decimal
			continue;
		}

		int order = (pi_array[i] - '0') * 10 + (pi_array[i + 1] - '0');
		
		if(token_arr[order].count == 0){
			
			token_arr[order].token[0] = pi_array[i];
			token_arr[order].token[1] = pi_array[i+1];
			counter.token_count++; // counting the tokens
		}
		token_arr[order].count++; // increasing the occurence number of that token
	}
	
	int pointer = 0;

	for(i = 0; i < 100; i++){ // filling the actual token array with tokens
		if(token_arr[i].count != 0){
			*(counter.token_array + pointer) = *(token_arr + i);
			pointer++;
		}
	}
	fclose(pi_file); // closing pi file
	return;
}


Token *Counter::get_most_common_three(){
	static Token most_commons[3]; // initilizing an array for 3 most common elements 
	Token *temp1, *temp2, *temp3; // initilizing 3 element pointers
	int i, s = 0;

	if (counter.token_array[0].count > counter.token_array[1].count){ // pointing the sorted first three token by counts
		if (counter.token_array[0].count > counter.token_array[2].count){
			temp3 = &(counter.token_array[0]);
			if (counter.token_array[1].count > counter.token_array[2].count){
				temp1 = &(counter.token_array[2]);
				temp2 = &(counter.token_array[1]);
			}else{
				temp2 = &(counter.token_array[2]);
				temp1 = &(counter.token_array[1]);
			}
		}else{
			temp3 = &(counter.token_array[2]);
			temp1 = &(counter.token_array[1]);
			temp2 = &(counter.token_array[0]);
		}
	}else if(counter.token_array[1].count > counter.token_array[2].count){
		temp3 = &(counter.token_array[1]);
		if (counter.token_array[2].count > counter.token_array[0].count){
			temp1 = &(counter.token_array[0]);
			temp2 = &(counter.token_array[2]);
		}else{
			temp2 = &(counter.token_array[2]);
			temp1 = &(counter.token_array[0]);
		}
	}else{
		temp3 = &(counter.token_array[2]);
		temp1 = &(counter.token_array[0]);
		temp2 = &(counter.token_array[1]);
	}


	for(i = 3; i < counter.token_count; i++){ // looking through all the tokens and getting the greatest 3 count

		s = counter.token_array[i].count; // count of current element

		if(temp1->count < s){ //checking if the greater count is reached, if so, taking that element
			if (temp2->count < s){
				if(temp3->count < s){
					temp1 = temp2;
					temp2 = temp3;
					temp3 = &(counter.token_array[i]);
				}else{
					temp1 = temp2;
					temp2 = &(counter.token_array[i]);
				}
			}else{
				temp1 = &(counter.token_array[i]);
			}
		}
	}

	*(most_commons + 2) = *temp1;
	*(most_commons + 1) = *temp2;
	*(most_commons) = *temp3;

	return most_commons;
}

/*
STUDENT NAME: SENIHA SERRA BOZKURT
STUDENT ID: 150190710
CLASS: BLG 223E - CRN: 11624
*/
