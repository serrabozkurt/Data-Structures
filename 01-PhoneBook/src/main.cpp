#include <stdlib.h>
#include <iostream>

using namespace std;

#include "menu.h"


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



