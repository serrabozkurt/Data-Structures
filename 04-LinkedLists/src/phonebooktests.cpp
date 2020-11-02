#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h> /* time */

#include "phonebooktests.h"
#include "phone_record.h"
void testphonebook()
{
    Phone_List phonelist;
    phonelist.create();
    read_fromfile(phonelist, "test_phonebook.dat");

    srand(clock());
    randomfill(phonelist, 10000);
    test(phonelist, 100);

    write_tofile(phonelist, "test_phonebook.dat");
    phonelist.clear();
}

void test(Phone_List& phonelist, int trials)
{

    const short namelen = 6;
    char name[namelen];

    clock_t start = clock();
    for (int i = 0; i < trials; i++)
    {
        randstr(name, namelen, 65, 26);
        phonelist.search(name);
    }

    clock_t end = clock();

    cout << "It took " << (double)(end - start) * 1000 / CLOCKS_PER_SEC << " milliseconds" << endl;

    getchar();
}

void randomfill(Phone_List& phonelist, int numofrecords)
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
        strncpy(newrecord.name, name, namelen);
        strncpy(newrecord.phonenum, phone, phonelen);
        phonelist.insert(&newrecord);
    }
}

void randstr(char str[], int len, int start, int end)
{

    for (int i = 0; i < len - 1; i++)
        str[i] = ((char)(start + rand() % end));

    str[len - 1] = '\0';
}
