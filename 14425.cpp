#include <iostream>
#include <string>
#include <set>
using namespace std;

int n, m, answer;
set<string> s;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s.insert(str);
    }

}

void Solve()
{
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if (s.find(str) != s.end())
            answer++;
    }

    cout << answer << '\n';
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}