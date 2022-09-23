#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string str1, str2;
        cin >> str1 >> str2;
        if (str1 == str2)
            cout << "OK\n";
        else
            cout << "ERROR\n";
    }
    return 0;
}