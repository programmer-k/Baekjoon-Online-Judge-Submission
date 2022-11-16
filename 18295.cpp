#include <iostream>
#include <string>
#include <set>
using namespace std;

int n;
set<int> numbers;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str.length() <= 8)
            numbers.insert(atoi(str.c_str()));
    }
}

void Solve()
{
    int i = 0;
    for (set<int>::iterator it = numbers.find(0); it != numbers.end(); it++, i++)
    {
        if (i != *it)
            break;
    }
    cout << i << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}