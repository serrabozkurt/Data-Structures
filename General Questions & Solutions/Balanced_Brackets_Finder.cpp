/*
STUDENT NAME: SENIHA SERRA BOZKURT
STUDENT ID: 150190710
CLASS: BLG 223E - CRN: 11624
*/
/*
Solve the following problem by filling the required places in the skeleton code. 

We want to check whether given input has proper matching parenthesis or not?  For example ( ) [ ] and [ ( ) ] has proper matching parenthesis but
 )( or ( [ ) ]  not. Let 0,1, 2, 3, 4 denote different types of left parenthesis such as (, [, ..  and 5, 6, 7, 8, 9 denote corresponding right 
 parenthesis such as ), ], ... Therefore 0-5,1-6, 2-7, 3-8, 4-9 are the parenthesis pairs that need to match. For example 1649 or 1496 has proper 
 matching parenthesis but 61 or 1946 not. We will provide you ten digit sequences such as 2334345666 and ask you to output TRUE if it is a proper 
 matching and FALSE if it is not. For example  1111166666, 2740591638 and 1327272786 should return TRUE; 3654112344 and 0000005555 should return FALSE.

You can use any library that you want. Also, you can ignore to check whether the user input contains numerical or alphabetical values.

*/

#include <stack>
#include <map>
#include <iostream>

#define INPUT_LENGTH 10
using namespace std;


bool check(char input[INPUT_LENGTH])
{
	map<char, char> strMap;
	strMap['0']  = '5';
	strMap['1']  = '6';
	strMap['2']  = '7';
	strMap['3']  = '8';
	strMap['4']  = '9';

	stack<char> s;
	char element;

	for(int i=0; i<10; i++){

		if (input[i] >= '0' && input[i] <= '4'){// if its an opening paranthesis, we will add it to the stack
			s.push(input[i]);
		}
		
		else if(!s.empty()) {
			element = s.top();
			
			if(strMap[element] != input[i]) // if a closing paranthesis came and it was not opened before, 
				return false; //then there's no way to go back in the stack and add an opening paranthesis, so it will never be true.
			else
				s.pop();
		}
		else
			return false; //if a closing paranthesis came and stack is empty, then there's no way to eliminate it 
	}
	return (s.empty()); 
}


int main(){	
	char input[10];
	cout<<"Enter the input:"<<endl;
	cin.getline(input,INPUT_LENGTH+1);
	if(check(input))
		cout<<"TRUE"<<endl;
	else
		cout<<"FALSE"<<endl;
	
	return 0;
}
