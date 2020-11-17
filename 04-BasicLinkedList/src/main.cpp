#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

#define ARRAY_CAP 100

double stdev(int[ARRAY_CAP], double, int);

int main()
{

    int grades[ARRAY_CAP];
    int count = 0;
    double acc = 0;

    cout << "Please input grade. Input -1 to stop" << endl;

    while (true)
    {
        cout << endl
             << "Next grade ";
        cin >> grades[count];

        if (grades[count] == -1)
            break;

        acc += grades[count];
        count++;
    }

    double average = 0;
    if (count != 0)
        average = acc / count;

    cout << "Average grade score is: " << average << endl;
    cout << "Stdev of grades is: " << stdev(grades, average, count) << endl;

    system("pause");
    return EXIT_SUCCESS;
}

double stdev(int grades[ARRAY_CAP], double average, int grade_count)
{

    if (grade_count == 0)
        return 0;

    double stdev = 0;

    for (int i = 0; i < grade_count; i++)
        stdev += pow(grades[i] - average, 2);

    return sqrt(stdev / grade_count);
}