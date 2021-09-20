/*Question#2-A palindrome is a word, number, phrase, or other sequence of characters 
which reads the same backward as forward, such as madam, racecar. Write a function
"char* question2answer(char *instring)" which
takes an argument string and turns it into a palindrome-like string but with a single 
difference from the classical definition. The string will consist of numerical values and 
the first half of the produced string will consist of numbers smaller (-2) than the second
half numbers such as in input=1234 output=2101234 instead of "4321234".  
If you find a negative number during subtraction put 0 instead such as in input=2002 output=0002002
You are not allowed to use c++ strings in your answer. 
Use either character arrays or pointers.
The only function that you may use from string class
is the "strlen" function*/

#ifndef HEADERFILE_H
#define HEADERFILE_H
#include <iostream>
#include <string.h>
#endif
using namespace std;

char* question2answer(char *instring){
	
	char *outstring;
	int x = strlen(instring);
	outstring = new char[2*x+1];

	for(int i = x; i<2*x; i++){
		outstring[i-1] = instring[i-x];

		if(i != ((2*x)-1)){
			if (instring[(2*x)-i-1] > 50){
				outstring[i-x] = instring[(2*x)-i-1] - 2;
			}
			else{
				outstring[i-x] = '0';
			}
		}
	}
	
	outstring[2*x-1] = '\0';
	
	return outstring;
}

/* @Author
Student Name: SENIHA SERRA BOZKURT
Student ID : 150190710 
Date: 08 DEC 2020
*/