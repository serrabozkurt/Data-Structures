#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

using namespace std;

#include "fileoperations.h"

void PhonebookFile::create_file(const char *fname)
{
	filename=new char[strlen(fname)+1];
	strncpy(filename, fname, strlen(fname));
	filename[strlen(fname)] ='\0';
	records = new Phone_Record[INIT_SIZE];
	size = INIT_SIZE;
	phonebook.open(filename, fstream::in | fstream::binary);
	if (!phonebook.is_open())
	{
		phonebook.open(filename, fstream::out | fstream::binary);
		if (!phonebook.is_open())
		{
			cerr << "Cannot open file";
			exit(1);
		}
	}
	else
	{
		string temp_name;
		string temp_phonenum;

		phonebook >> temp_name >> temp_phonenum;
		while (!phonebook.eof())
		{
			if (records_count == size)
				increaseSize();

			records[records_count].name = new char[strlen(temp_name.c_str()) + 1];
			strncpy(records[records_count].name, temp_name.c_str(), strlen(temp_name.c_str()));
			records[records_count].name[strlen(temp_name.c_str())] = '\0';

			cout << temp_phonenum.c_str() << endl;
			records[records_count].phonenum = new char[strlen(temp_phonenum.c_str()) + 1];
			strncpy(records[records_count].phonenum, temp_phonenum.c_str(), strlen(temp_phonenum.c_str()));
			records[records_count].phonenum[strlen(temp_phonenum.c_str())] = '\0';

			records_count++;
			phonebook >> temp_name >> temp_phonenum;
		}
	}
	phonebook.close();
}

void PhonebookFile::close_file(){
	phonebook.open(filename, fstream::out | std::ofstream::trunc | fstream::binary);
	if (!phonebook.is_open())
	{
		cerr << "Cannot open file" << endl;
		exit(1);
	}
	for (int i = 0; i < records_count; i++)
	{
		phonebook << records[i].name << " " << records[i].phonenum << endl;
		delete[] records[i].name;
		delete[] records[i].phonenum;
	}
	phonebook.close();

	delete[] records;
	delete[] filename;
}

void PhonebookFile::add_to_file(Phone_Record *nrptr){
	if (records_count == size)
	{
		increaseSize();
	}
	records[records_count].name = new char[strlen(nrptr->name) + 1];
	strncpy(records[records_count].name, nrptr->name, strlen(nrptr->name));
	records[records_count].name[strlen(nrptr->name)]='\0';

	records[records_count].phonenum = new char[strlen(nrptr->phonenum) + 1];
	strncpy(records[records_count].phonenum, nrptr->phonenum, strlen(nrptr->phonenum));
	records[records_count].phonenum[strlen(nrptr->phonenum)]='\0';

	records_count++;
}

int PhonebookFile::search_file(const char *desired){
	bool all = false;
	int found = 0;
	if (strcmp(desired, "*") == 0)
		all = true;

	for (int i = 0; i < records_count; i++)
	{
		if (!all && strncasecmp(records[i].name, desired, strlen(desired)) != 0) //compares, at most, the first n characters of string1 and string2 without sensitivity to case.
			continue;
		cout << i << "." << records[i].name << " " << records[i].phonenum << endl;
		found++;
	}

	return found;
}

void PhonebookFile::update_file(int recordnum,Phone_Record *nrptr){
	delete[] records[recordnum].name;
	records[recordnum].name = new char[strlen(nrptr->name) + 1];
	strncpy(records[recordnum].name, nrptr->name, strlen(nrptr->name));
	records[recordnum].name[strlen(nrptr->name)]='\0';
	
	delete[] records[recordnum].phonenum;
	records[recordnum].phonenum = new char[strlen(nrptr->phonenum) + 1];
	strncpy(records[recordnum].phonenum, nrptr->phonenum, strlen(nrptr->phonenum));
	records[recordnum].phonenum[strlen(nrptr->phonenum)] = '\0';
}

void PhonebookFile::remove_from_file(int recordnum){
	delete[] records[recordnum].name;
	delete[] records[recordnum].phonenum;

	for (; recordnum < records_count; recordnum++)
	{
		if (recordnum + 1 < size)
			records[recordnum] = records[recordnum + 1];

	}
	records_count--;
}

void PhonebookFile::increaseSize()
{
	size = size * 2;
	Phone_Record *temp = new Phone_Record[size];
	cout << "Increasing size" << endl;
	for (int i = 0; i < records_count; i++)
	{
		temp[i].name = new char[strlen(records[i].name) + 1]; //'\0'
		strncpy(temp[i].name, records[i].name, strlen(records[i].name));
		temp[i].name[strlen(records[i].name)]='\0';
		delete[] records[i].name;

		temp[i].phonenum = new char[strlen(records[i].phonenum) + 1]; //'\0'
		strncpy(temp[i].phonenum, records[i].phonenum, strlen(records[i].phonenum));
		temp[i].name[strlen(records[i].phonenum)] = '\0';
		delete[] records[i].phonenum;
	}
	delete[] records;
	records = temp;
}