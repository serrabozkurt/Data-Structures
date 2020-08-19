#include <stdlib.h>
#include <iostream>

using namespace std;

void print_menu();
bool perform_operation(char);

int main(){

    bool end = false; 
	char choice; 
	while (!end) { 
		print_menu(); 
		cin >> choice;
        end = true;
		end = perform_operation(choice); 
	} 	
	return EXIT_SUCCESS;

}

void print_menu(){
	//system("clear");     //https://www.cplusplus.com/articles/4z18T05o/
	cout << endl << endl;
	cout << "Phone Book Application" << endl;
	cout << "Choose an operation" << endl;
	cout << "S: Record Search" << endl;
	cout << "A: Record Add" << endl;
	cout << "U: Record Update" << endl;
	cout << "D: Record Delete" << endl;	
	cout << "E: Exit" << endl;	
	cout << endl;
	cout << "Enter a choice {S,A,U,D,E}: ";
}

bool perform_operation(char choice){
	bool terminate=false;
	switch (choice) { 
		case 'S': case 's': 
			//search_record();
			break; 
		case 'A': case 'a': 
			//add_record();
			break; 
		case 'U': case 'u': 
			//update_record();
			break;
		case 'D': case 'd': 
			//delete_record();
			break;
		case 'E': case 'e': 
			cout << "Are you sure you want to exit the program? (Y/N):";
			cin >> choice;
			if(choice=='Y' || choice=='y')
				terminate=true; 
				break; 
		default: 
			cout << "Error: You have entered an invalid choice" << endl; 
			cout << "Please try again {S, A, U, D, E} :" ;
			cin >> choice;
			terminate = perform_operation(choice);
			break; 
	}
	return terminate;
}

