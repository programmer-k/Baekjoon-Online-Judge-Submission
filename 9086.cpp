#include <iostream>
#include <string>
using namespace std;

int t;

int main(void)
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string str;
        cin >> str;
        cout << str[0] << str[str.length() - 1] << '\n';
    }
    return 0;
}