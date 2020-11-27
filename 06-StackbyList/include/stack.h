#pragma once
typedef char StackDataType;
struct Node
{
    StackDataType data;
    Node *next;
};

struct Stack
{
    Node *head;
    
    void create();
    void close();
    void push(StackDataType);
    StackDataType pop();
    bool isempty();
    void print_stack();
};
