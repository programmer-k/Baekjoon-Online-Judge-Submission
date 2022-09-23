#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string str1, str2;
    cin >> str1 >> str2;
    if (str1.length() >= str2.length())
        cout << "go" << '\n';
    else
        cout << "no" << '\n';
    return 0;
}