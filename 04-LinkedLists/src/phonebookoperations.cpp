#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

#include "menu.h"
#include "phone_record.h"

void add_record(Phone_List &phonelist)
{
	Phone_Record newrecord;
	cout << "Please enter contact information you want to add" << endl;
	cout << "Name : ";
	cin.ignore(1000, '\n');
	cin.getline(newrecord.name, NAME_LENGTH);
	cout << "Phone number :";
	cin >> setw(PHONENUM_LENGTH) >> newrecord.phonenum; //setw --> iomanip
	phonelist.insert(&newrecord);
	cout << "Record added" << endl;
	getchar(); //getchar --> stdio
}

void search_record(Phone_List &phonelist)
{
	char name[NAME_LENGTH];
	cout << "Please enter the name of the person you want to search for (press'*'for full list):" << endl;
	cin.ignore(1000, '\n');
	cin.getline(name, NAME_LENGTH);
	if (phonelist.search(name) == 0)
	{
		cout << "Could not find a record matching your search criteria" << endl;
	}
	getchar();
}

void update_record(Phone_List &phonelist)
{
	char name[NAME_LENGTH];
	int choice;
	cout << "Please enter the name of the person whose record you want to update (press'*'for full list):" << endl;
	cin.ignore(1000, '\n');
	cin.getline(name, NAME_LENGTH);
	int personcount = phonelist.search(name);
	if (personcount == 0)
	{
		cout << "Could not find a record matching your search criteria" << endl;
	}
	else
	{
		if (personcount == 1)
		{
			cout << "Record found." << endl;
			cout << " If you want to update this record please enter its number (Enter -1 to exit without 				   performing any operations): ";
		}
		else
			cout << "Enter the number of the record you want to update (Enter -1 to exit without performing any operations): ";
		cin >> choice;
		if (choice == -1)
			return;
		Phone_Record newrecord;
		cout << "Please enter current contact information" << endl;
		cout << "Name : ";
		cin.ignore(1000, '\n');
		cin.getline(newrecord.name, NAME_LENGTH);
		cout << "Phone number :";
		cin >> setw(PHONENUM_LENGTH) >> newrecord.phonenum;
		phonelist.update(choice, &newrecord);
		cout << "Record successfully updated" << endl;
	}
	getchar();
}

void delete_record(Phone_List &phonelist)
{
	char name[NAME_LENGTH];
	int choice;
	cout << "Please enter the name of the person whose record you want to delete (press'*'for full list):" << endl;
	cin.ignore(1000, '\n');
	cin.getline(name, NAME_LENGTH);
	int personcount = phonelist.search(name);
	if (personcount == 0)
	{
		cout << " Could not find a record matching your search criteria " << endl;
	}
	else
	{
		if (personcount == 1)
		{
			cout << "Record found." << endl;
			cout << "If you want to delete this record please enter its number (Enter -1 to exit without performing any operations): ";
		}
		else
			cout << "Enter the number of the record you want to delete (Enter -1 to exit without performing any operations): ";
		cin >> choice;
		if (choice == -1)
			return;
		phonelist.remove(choice);
		cout << "Record deleted" << endl;
	}
	getchar();
}

void clear_records(Phone_List &phonelist)
{
	char choice;
	cout << "Are you sure you want to clear all the records? (Y/N):" << endl;
	cin >> choice;
	if (choice == 'Y' || choice == 'y'){
		phonelist.clear();
		cout << "All records cleared!!!";
	}
	else
	{
		cout << "Records kept. Returning back to menu.";
	}
	
	getchar();
}
