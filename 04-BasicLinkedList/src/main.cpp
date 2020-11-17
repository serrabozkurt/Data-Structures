#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

double stdev(int *, double, int);

int main()
{

    int *grades;
    int count = 0, array_cap = 0;
    double acc = 0;

    cout << "How many grades you plan to input at most" << endl;
    cin >> array_cap;

    grades = new int[array_cap];

    cout << "Please input grades. Input -1 to stop" << endl;

    while (count < array_cap)
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
    delete[] grades;
    return EXIT_SUCCESS;
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