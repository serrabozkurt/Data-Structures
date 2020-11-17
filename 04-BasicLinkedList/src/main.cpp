#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct LinkedList
{
    Node *head;
    Node *tail;
};

void add_to_list(LinkedList &, int);
void print_list(LinkedList &);
void remove_list(LinkedList &);
double stdev(LinkedList &, double, int);

int main()
{
    LinkedList a_list;
    a_list.head = NULL;
    a_list.tail = NULL;

    int cur_grade = 0;
    int count = 0;
    double acc = 0;

    cout << "Please input grades. Input -1 to stop" << endl;

    while (true)
    {
        cout << endl
             << "Next grade ";
        cin >> cur_grade;

        if (cur_grade == -1)
            break;

        acc += cur_grade;
        add_to_list(a_list, cur_grade);
        count++;
    }

    print_list(a_list);
    double average = 0;
    if (count != 0)
        average = acc / count;

    cout << "Average grade score is: " << average << endl;
    cout << "Stdev of grades is: " << stdev(a_list, average, count) << endl;

    system("pause");
    remove_list(a_list);
    return EXIT_SUCCESS;
}

void remove_list(LinkedList &list)
{
    Node *ptr = list.head;
    Node *todelete;

    while (ptr)
    {
        todelete = ptr;
        ptr = ptr->next;
        delete todelete;
    }
}

void print_list(LinkedList &list)
{
    Node *ptr = list.head;

    cout << "||->";
    while (ptr != list.tail)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << ptr->data << " |" << endl;
}

void add_to_list(LinkedList &list, int grade)
{
    Node *toadd = new Node;
    toadd->data = grade;
    toadd->next = NULL;

    if (!list.head)
    { //add to empty
        list.head = toadd;
        list.tail = toadd;
    }
    else
    {
        Node *ptr = list.head;
        while (ptr && ptr->next && ptr->next->data < toadd->data)
            ptr = ptr->next;

        if (ptr == list.tail && ptr->data < toadd->data)
        { //add to tail
            list.tail->next = toadd;
            list.tail = toadd;
        }
        else if (ptr == list.head && ptr->data > toadd->data)
        { //add to head
            toadd->next = list.head;
            list.head = toadd;
        }
        else
        { //add in between
            toadd->next = ptr->next;
            ptr->next = toadd;
        }
    }
}

double stdev(LinkedList &list, double average, int grade_count)
{

    if (grade_count == 0)
        return 0;

    double stdev = 0;

    Node *ptr = list.head;

    while (ptr)
    {
        stdev += pow(ptr->data - average, 2);
        ptr = ptr->next;
    }

    return sqrt(stdev / grade_count);
}