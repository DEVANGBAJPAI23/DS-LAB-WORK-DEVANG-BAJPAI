#include <iostream>
using namespace std;

bool palindrome(string s)
{
    int i = 0, j = s.size() - 1;
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
