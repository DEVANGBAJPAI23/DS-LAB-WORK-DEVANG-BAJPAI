#include <iostream>
using namespace std;

int main()
{
    int marks[5][5];
    int total[5] = {0};
    float average[5] = {0};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> marks[i][j];
            total[i] += marks[i][j];
        }

    }

    for (int i = 0; i < 5; i++)
    {
        cout << "Total marks of student " << i + 1 << ": " << total[i] << endl;
    }

    for (int j = 0; j < 5; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            average[j] += marks[i][j];
        }
        average[j] /= 5;
    }

    for (int j = 0; j < 5; j++)
    {
        cout << "Average marks of subject " << j + 1 << ": " << average[j] << endl;
    }

    return 0;
}
