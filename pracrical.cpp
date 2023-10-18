#include <iostream>
using namespace std;

// Taking input of marks in 2D array and calculating total of every student and average of every subject
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

// palindrome
bool palindrome(string s)
{
    int i = 0, j = s.size();
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int main()
{
    string str;
    cout << "Enter string: ";
    getline(cin, str);

    if (palindrome(str))
    {
        cout << "String is Palindrome";
    }
    else
    {
        cout << "Not palindrome";
    }

    return 0;
}

// linear and binary search
int linearSearch(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

// Function for binary search
int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}