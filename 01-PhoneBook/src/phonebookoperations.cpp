#include <stdlib.h>
#include <iostream>

using namespace std;

#include "phonebookoperations.h"

void add_record(){
	Phone_Record newrecord;	
	cout << "Please enter contact information 	you want to add" << endl;
	cout << "Name : " ;
	cin.ignore(1000, '\n');	
	cin.getline(newrecord.name,NAME_LENGTH);
	cout << "Phone number :";
	cin >> setw(PHONENUM_LENGTH) 	     
     >>newrecord.phonenum;
	book.add(&newrecord);
	cout << "Record added" << endl;
	getchar();
};
