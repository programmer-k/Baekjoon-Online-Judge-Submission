#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n;
queue<int> q;

void GetInput()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n;
}

void Solve()
{
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;

        if (str == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << '\n';
                q.pop();
            }
            else
                cout << -1 << '\n';
        }
        else if (str == "size")
        {
            cout << q.size() << '\n';
        }
        else if (str == "empty")
        {
            if (q.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (str == "front")
        {
            if (!q.empty())
                cout << q.front() << '\n';
            else
                cout << -1 << '\n';
        }
        else if (str == "back")
        {
            if (!q.empty())
                cout << q.back() << '\n';
            else
                cout << -1 << '\n';
        }
        else
        {
            int n;
            cin >> n;
            q.push(n);
        }
    }
}

int main(void)
{
    GetInput();
    Solve();
    return 0;
}