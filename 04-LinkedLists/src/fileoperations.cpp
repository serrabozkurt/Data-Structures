#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

using namespace std;

#include "fileoperations.h"
#include "phone_record.h"

void read_fromfile(Phone_List& alist, const char *filename)
{
	FILE* phonebook;
	if (!(phonebook = fopen(filename, "r+")))
		if (!(phonebook = fopen(filename, "w+")))
		{
			cerr << "File could not be opened" << endl;
			exit(1);
		}
	fseek(phonebook, 0, SEEK_SET);
	while (!feof(phonebook))
	{
		Phone_Record *newrecord = new Phone_Record;
		if(fread(newrecord, sizeof(Phone_Record), 1, phonebook)!=1)
			break;
		alist.insert(newrecord);
	}
	fclose(phonebook);
}

void write_tofile(Phone_List& alist, const char *filename)
{
	FILE *phonebook;

	Phone_Record record;
	Phone_Node *p;
	if (!(phonebook = fopen(filename, "w+")))
	{
		cerr << "File could not be opened" << endl;
		exit(1);
	}
	p = alist.head;
	while (p)
	{
		fwrite(p->phone_record, sizeof(Phone_Record), 1, phonebook);
		p = p->next;
	}
	fclose(phonebook);
}