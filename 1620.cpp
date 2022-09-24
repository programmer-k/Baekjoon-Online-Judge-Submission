#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;

int n, m;
map<int, string> intToString;
map<string, int> stringToInt;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string str;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> str;
        intToString[i] = str;
        stringToInt[str] = i;
    }
}

void Solve()
{
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if (str[0] >= '0' && str[0] <= '9')
        {
            int num = atoi(str.c_str());
            cout << intToString[num] << '\n';
        }
        else
            cout << stringToInt[str] << '\n';
    }
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}