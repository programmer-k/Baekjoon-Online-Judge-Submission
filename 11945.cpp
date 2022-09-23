#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n, m;
    string str[10];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> str[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = str[i].length() - 1; j >= 0; j--)
            cout << str[i][j];
        cout << '\n';
    }
    return 0;
}