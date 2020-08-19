#include <stdlib.h>
#include <iostream>

using namespace std;

#include "menu.h"
#include "fileoperations.h"

typedef File Datastructure;
Datastructure book;

int main(){

	book.create();
    
	bool end = false; 
	char choice; 
	while (!end) { 
		print_menu(); 
		cin >> choice;
        end = true;
		end = perform_operation(choice); 
	} 	

	book.close();
	
	return EXIT_SUCCESS;   //-->stdlib.h

}



