#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip> 

using namespace std;

#include "menu.h"
#include "fileoperations.h"

void add_record(PhonebookFile bookfile){
	Phone_Record newrecord;	
	cout << "Please enter contact information 	you want to add" << endl;
	cout << "Name : " ;
	cin.ignore(1000, '\n');	
	cin.getline(newrecord.name,NAME_LENGTH);
	cout << "Phone number :";
	cin >> setw(PHONENUM_LENGTH) >>newrecord.phonenum;  //setw --> iomanip
	bookfile.add(&newrecord);
	cout << "Record added" << endl;
	getchar();   //getchar --> stdio
}

void search_record(PhonebookFile bookfile){
	char name[NAME_LENGTH];
	cout << "Please enter the name of the person you want to search for (press'*'for full list):" << endl;
	cin.ignore(1000, '\n');
	cin.getline(name,NAME_LENGTH);		
	if(bookfile.search(name)==0){
		cout << "Could not find a record matching your search criteria" << endl;
	}
	getchar();
}
