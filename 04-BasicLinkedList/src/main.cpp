#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{

    int grade = 0;
    int count = 0;
    double acc = 0;

    cout << "Please input grade. Input -1 to stop" << endl;

    while (true)
    {
        cout << endl << "Next grade ";
        cin >> grade;

        if (grade == -1)
            break;

        acc += grade;
        count++;
    }

    double average=0;
    if(count!=0)
        average = acc / count;

    cout << "Average grade score is: " << average << endl;

    system("pause");
    return EXIT_SUCCESS;
}