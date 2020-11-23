#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h> /* time */

#include "phonebooktests.h"

void testphonebook()
{
    PhonebookFile bookfile;
    bookfile.create_file("test_phonebook.dat");

    srand(clock());
    randomfill(bookfile, 10000);
    test(bookfile, 1000);

    bookfile.close_file();
}

void test(PhonebookFile& bookfile, int trials)
{

    const short namelen = 6;
    char name[namelen];

    clock_t start = clock();
    for (int i = 0; i < trials; i++)
    {
        randstr(name, namelen, 65, 26);
        bookfile.search_file(name);
    }

    clock_t end = clock();

    cout << "It took " << (double)(end - start) * 1000 / CLOCKS_PER_SEC << " milliseconds" << endl;

    getchar();
}

void randomfill(PhonebookFile& bookfile, int numofrecords)
{

    const short namelen = 6;
    char name[namelen];
    const short phonelen = 8;
    char phone[phonelen];

    for (int i = 0; i < numofrecords; i++)
    {

        randstr(name, namelen, 65, 26);
        randstr(phone, phonelen, 48, 10);

        Phone_Record newrecord;
        newrecord.name = new char[namelen];
        newrecord.phonenum = new char[phonelen];
        strncpy(newrecord.name, name, namelen);
        strncpy(newrecord.phonenum, phone, phonelen);
        bookfile.add_to_file(&newrecord);
    }
}

void randstr(char str[], int len, int start, int end)
{

    for (int i = 0; i < len - 1; i++)
        str[i] = ((char)(start + rand() % end));

    str[len - 1] = '\0';
}
