#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str;
    cin >> str;
    for (unsigned int i = 0; i < str.length(); i++)
        if (str[i] >= 'a')
            str[i] = str[i] - ('a' - 'A');
        else
            str[i] = str[i] + ('a' - 'A');
    cout << str << '\n';
    return 0;
}