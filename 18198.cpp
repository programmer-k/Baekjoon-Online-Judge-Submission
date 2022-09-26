#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(void)
{
    string str;
    cin >> str;
    int a = 0, b = 0;
    for (unsigned int i = 0; i < str.length(); i++)
    {
        if (str[i++] == 'A')
            a += str[i] - '0';
        else
            b += str[i] - '0';
    }
    if (a > b)
        cout << 'A';
    else
        cout << 'B';
    return 0;
}