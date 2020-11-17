#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define ARRAY_CAP 3

double stdev(int *, double, int);
bool extend_array(int **, int, int);

int main()
{

    int *grades;
    int current_cap = ARRAY_CAP;
    int count = 0;
    double acc = 0;

    grades = new int[current_cap];

    cout << "Please input grades. Input -1 to stop" << endl;

    while (count < current_cap)
    {
        cout << endl
             << "Next grade ";
        cin >> grades[count];

        if (grades[count] == -1)
            break;

        acc += grades[count];
        count++;

        if (count == current_cap)
        {
            if (extend_array(&grades, current_cap, ARRAY_CAP))
                current_cap += ARRAY_CAP;
        }
    }

    double average = 0;
    if (count != 0)
        average = acc / count;

    cout << "Average grade score is: " << average << endl;
    cout << "Stdev of grades is: " << stdev(grades, average, count) << endl;

    system("pause");
    return EXIT_SUCCESS;
}

bool extend_array(int **arr, int current, int add)
{
    int *new_arr = new int[current + add];

    cout << "Extending array..." << endl;

    for (int i = 0; i < current; i++)
        new_arr[i] = (*arr)[i];

    delete[] arr;

    arr = &new_arr;

    return true;
}

double stdev(int *grades, double average, int grade_count)
{

    if (grade_count == 0)
        return 0;

    double stdev = 0;

    for (int i = 0; i < grade_count; i++)
        stdev += pow(grades[i] - average, 2);

    return sqrt(stdev / grade_count);
}