#pragma once
#include "phone_node.h"
#include "phone_record.h"

struct Phone_List
{
    Phone_Node* head;
    int nodecount;
    void create();
    void clear();
    void printList();
    void insert(Phone_Record*);
    void remove(int ordernum);
    int search(char *);
    void update(int recordnum, Phone_Record*);
};