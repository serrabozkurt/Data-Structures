#include <iostream>
#include <stdlib.h>
using namespace std;

#include "fileoperations.h"

void File::create(){	
	filename="phonebook.txt";
	phonebook = fopen( filename, "r+" );
	if(!phonebook){
		if(!(phonebook=fopen(filename,"w+"))){
		    cerr << "Cannot open file" << endl;
		    exit(1);   //--> stdlib.h 
		}
	}
}

void File::close (){
	fclose(phonebook);
}
